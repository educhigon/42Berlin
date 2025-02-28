CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a
GNL_DIR = get_next_line
PRINTF_DIR = ft_printf

SRC_DIRS = Converters Checkers List Mem_Handler Printers Str_Handler Str_Modifiers

SRC = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJ = $(SRC:.c=.o)

GNL_SRC = $(wildcard $(GNL_DIR)/*.c)
GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME) ft_printf

$(NAME): $(OBJ) $(GNL_OBJ)
	ar rcs $(NAME) $(OBJ) $(GNL_OBJ)

ft_printf:
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all