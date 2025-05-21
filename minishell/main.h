/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 16:51:18 by edugonza          #+#    #+#             */
/*   Updated: 2025-05-06 16:51:18 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H

# include "Libft_power/libft.h"

# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

#define Y		"\033[1;33m"
#define G		"\033[1;32m"
#define C		"\033[1;36m"
#define RED		"\033[1;31m"
#define RST		"\033[0m"

#define PROMPT "?> "

////////////////////////////
///////   TOKENS   /////////
////////////////////////////

typedef struct s_token	t_token;

typedef enum e_token_type {
	TOKEN_WORD,
	TOKEN_SPACE,
	TOKEN_REDIRECT_IN, // < (2)
	TOKEN_REDIRECT_HEREDOC, // << (3)
	TOKEN_REDIRECT_OUT_APP, // > (4)
	TOKEN_REDIRECT_OUT_TRUNC, // >> (5)
	TOKEN_PIPE,
	TOKEN_D_QUOTE,
	TOKEN_S_QUOTE,
	TOKEN_SEQUENCE,
	TOKEN_EOF,
	TOKEN_ERROR
}	t_token_type;

struct s_token
{
	char			*content;
	t_token_type	type;
	int				fully_quoted;
	size_t			len;
	t_token			*next;
};

//to keep track of where we are in the token list
typedef struct {
	t_token *current;
} Parser;



////////////////////////////
//////////   AST   /////////
////////////////////////////

//AST node types
typedef enum
{
	AST_COMMAND,
	AST_REDIRECT,
	AST_PIPELINE,
	AST_SEQUENCE,
	AST_ERROR
} ASTNodeType;

// AST node structure
typedef struct ASTNode ASTNode;

typedef struct ASTNode
{
	ASTNodeType type;
	ASTNode *parent;
	union {
		struct {
			char **argv;
		} command;	//COMMAND node holds an array of strings (arguments)

		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} binary;	//PIPELINE or SEQUENCE node holds two child nodes (left and right)

		struct {
			struct ASTNode *command;
			char **filename;
			int redirect_type; // 0 for input (<), 1 for HERE_DOC (<<), 2 for output (>), 3 for output APP (>>), -1 for NULL
		} redirect;	//REDIRECT node holds a command and a file name.
	};
} ASTNode;



// Tokenizer Utils
int	ismeta(char c);
int	ft_isspace(char c);
void	skip_whitespace(char **s);
void	skip_whitespace_with_token(char **s,  t_token **tokens_ll);
void	free_token(t_token **token_ll);

// Get Token
void	get_double_quote_token(char **s, t_token **tokens_ll);
void	get_greater_than_token(char **s, t_token **tokens_ll);
void	get_less_than_token(char **s, t_token **tokens_ll);
void	get_pipe_token(char **s, t_token **tokens_ll);
void	get_single_quote_token(char **s, t_token **tokens_ll);
void	get_word_token(char **s, t_token **tokens_ll);
void get_EOF_token(char **s, t_token **tokens_ll);

// Get Token Type
t_token_type	get_token_type(char *line);

// Tokenizer
t_token	*tokenize(char *line);
t_token	*get_token(char *start, char *end);

// Libft_lists
void	del_content_token(void *content);
void	ft_lstadd_back_token(t_token **lst, t_token *new);
void	ft_lstclear_token(t_token **lst, void (*del)(void *));
void	ft_lstdelone_token(t_token *lst, void (*del)(void *));
t_token	*ft_token_last(t_token *lst);

// Utils
void	print_header(void);
void	print_tokens(t_token *token);
void print_ast_tree(ASTNode *node, const char *prefix, int is_last);

// AST
ASTNode *parse_line(Parser *parser, ASTNode *tree, t_token **tok);

// ASTree
ASTNode *parse(Parser *parser, ASTNode *tree);
ASTNode *parse_command(Parser *parser, ASTNode *tree, t_token **tok);


// ASTree Utils
void advance(Parser *parser);
t_token *next_tok(Parser *parser);
void build_word(t_token *tok, ASTNode *tree);
void build_name(t_token *tok, ASTNode *tree);
void free_tree(ASTNode *tree);


#endif
