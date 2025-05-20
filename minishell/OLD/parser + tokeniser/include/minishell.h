// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   minishell.h                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/09 10:52:33 by jkolosow          #+#    #+#             */
// /*   Updated: 2025/05/12 13:49:14 by joseph           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <stddef.h>

// #include <readline/readline.h>

// #define PROMPT "minishell$ "

// typedef struct s_token	t_token;

// typedef enum e_token_type {
// 	TOKEN_PIPE,
// 	TOKEN_REDIRECT_IN,
// 	TOKEN_REDIRECT_OUT_APP,
// 	TOKEN_REDIRECT_OUT_TRUNC,
// 	TOKEN_WORD,
// 	TOKEN_HEREDOC,
// 	TOKEN_D_QUOTE,
// 	TOKEN_S_QUOTE,
// 	TOKEN_SEQUENCE,	//new
// 	TOKEN_EOF		//new
// }	t_token_type;

// struct s_token
// {
// 	char			*content;
// 	t_token_type	type;
// 	int				fully_quoted;
// 	size_t			len;
// 	t_token			*next;
// };

// //AST node types
// typedef enum
// {
// 	AST_COMMAND,
// 	AST_PIPELINE,
// 	AST_SEQUENCE,
// 	AST_REDIRECT
// } ASTNodeType;

// // AST node structure
// typedef struct ASTNode
// {
// 	ASTNodeType type;
// 	union {
// 		struct {
// 			char **argv;
// 		} command;	//COMMAND node holds an array of strings (arguments)

// 		struct {
// 			struct ASTNode *left;
// 			struct ASTNode *right;
// 		} binary;	//PIPELINE or SEQUENCE node holds two child nodes (left and right)

// 		struct {
// 			struct ASTNode *command;
// 			char *filename;
// 			int redirect_type; // 0 for input (<), 1 for output (>)
// 		} redirect;	//REDIRECT node holds a command and a file name.
// 	};
// } ASTNode;

// //to keep track of where we are in the token list
// typedef struct {
// 	t_token *current;
// } Parser;



// void	del_content(void *content);
// int		ft_isspace(char c);
// void	ft_lstclear(t_token **lst, void (*del)(void *));
// void	ft_lstdelone(t_token *lst, void (*del)(void *));
// t_token	*ft_lstlast(t_token *lst);
// void	ft_lstadd_back(t_token **lst, t_token *new);
// void	*ft_memcpy(void *dest, const void *src, size_t n);
// size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
// size_t	ft_strlen(const char *s);
// void	get_double_quote_token(char **s, t_token **tokens_ll);
// void	get_greater_than_token(char **s, t_token **tokens_ll);
// void	get_less_than_token(char **s, t_token **tokens_ll);
// void	get_pipe_token(char **s, t_token **tokens_ll);
// void	get_single_quote_token(char **s, t_token **tokens_ll);
// t_token	*get_token(char *start, char *end);
// void	get_word_token(char **s, t_token **tokens_ll);
// int		ismeta(char c);
// void	print_tokens(t_token *token);
// void	skip_whitespace(char **s);
// t_token	*tokenize(char *line);


// void print_ast_tree(ASTNode *node, const char *prefix, int is_last);

// ASTNode *parse_command(Parser *parser);
// ASTNode *parse_pipeline(Parser *parser);
// ASTNode *parse_sequence(Parser *parser);
// ASTNode *parse(Parser *parser);
