CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = 	push_swap.c push_swap_utils.c  verifications.c start_sorting.c function_push.c  function_swap.c  function_rotate.c  function_reverse_rotate.c  sorting_a.c  sorting_b.c
OBJ = $(SRC:.c=.o)
LIBFT = Libft/libft.a
INCLUDES = -I Libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C Libft clean

fclean: clean
	rm -f $(NAME)
	make -C Libft fclean

re: fclean all


