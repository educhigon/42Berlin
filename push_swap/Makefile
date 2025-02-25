CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = 	push_swap.c push_swap_utils.c  verifications.c start_sorting.c  sorting_utils.c function_push.c  function_swap.c  function_rotate.c  function_reverse_rotate.c  sorting_a.c  sorting_b.c
OBJ = $(SRC:.c=.o)
LIBFT = Libft/libft.a
PRINTF = ft_printf/ft_printf.a
INCLUDES = -I Libft/ -I ft_printf/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C Libft

$(PRINTF):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C Libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C Libft fclean
	make -C ft_printf fclean

re: fclean all


