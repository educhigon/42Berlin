CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
SRC = 	push_swap.c push_swap_utils.c  verifications.c start_sorting.c  sorting_utils.c function_push.c  function_swap.c  function_rotate.c  function_reverse_rotate.c  sorting_a.c  sorting_b.c
OBJ = $(SRC:.c=.o)

LIBFT = Libft_power
LIBFT_A = Libft_power/libft.a
PRINTF = ft_printf
PRINTF_A = ft_printf/ft_printf.a
INCLUDES = -I Libft_power/ -I ft_printf/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT)

$(PRINTF_A):
	make -C $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean
	make -C $(PRINTF) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	make -C $(PRINTF) fclean

re: fclean all


