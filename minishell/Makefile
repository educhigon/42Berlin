CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell
NAME_H = main.h
# SRC_FOLDERS = tokens main parser expander executer builtins debug
# SRC = $(wildcard $(addsuffix /*.c, $(SRC_FOLDERS)))

SRC = \
	builtins/builtin_chooser.c \
	builtins/ft_echo.c \
	builtins/ft_cd.c \
	builtins/ft_env.c \
	builtins/ft_exit.c \
	builtins/ft_export.c \
	builtins/ft_export_utils.c \
	builtins/ft_pwd.c \
	builtins/ft_unset.c \
	builtins/print_sorted_env.c \
	executer/build_xble.c \
	executer/executor_command.c \
	executer/executor_pipe.c \
	executer/executor_redirect.c \
	executer/main_executer.c \
	executer/path_finder.c \
	executer/utils_heredoc.c \
	executer/utils_redirection.c \
	expander/expand_argument.c \
	expander/expander_command.c \
	expander/expander_redirect.c \
	expander/expand_tilde.c \
	expander/expand_variable.c \
	expander/quotes_empty.c \
	expander/quotes_single_double.c \
	expander/tree_expansion.c \
	expander/utils_expander.c \
	expander/utils_mem_expander.c \
	main/main.c \
	main/process_command.c \
	main/signals.c \
	main/utils.c \
	parser/ast.c \
	parser/astree_utils2.c \
	parser/astree_utils.c \
	parser/create_nodes.c \
	parser/parse_redirect.c \
	tokens/get_tokens.c \
	tokens/great_lesser_tokens.c \
	tokens/linked_list_utils2.c \
	tokens/linked_list_utils.c \
	tokens/tokenizer.c \
	tokens/tokenizer_errors.c \
	tokens/tokenizer_utils.c \
	tokens/token_type.c

OBJ = $(SRC:.c=.o)

LIBFT = Libft_power
LIBFT_A = Libft_power/libft.a
INCLUDES = -I Libft_power/ -I Libft_power/ft_printf/ -I Libft_power/get_next_line/

LINKERS = -lreadline

all: $(NAME)

############# Linking phase - creating the executable
############# Linkers are needed to link libraries
############# Example:

# $(NAME): $(OBJ) $(LIBFT_A)
# 	$(CC) $(OBJ) $(LIBFT_A) -o $(NAME) $(LINKERS)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(OBJ) $(LIBFT_A) -o $(NAME) $(LINKERS)

$(LIBFT_A):
	make -C $(LIBFT)

############# COMPILE FILES
############# Inlcude flags are meant for folders (Like LIBFT or PRITNF)
############# Example:
# %.o: %.c $(NAME_H)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c $(NAME_H)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
