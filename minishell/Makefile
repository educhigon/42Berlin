CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell
NAME_H = main.h
SRC = main.c utils.c tokenizer.c tokenizer_utils.c get_tokens.c linked_list_utils.c
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
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
