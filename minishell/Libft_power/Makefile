CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
GNL_DIR = get_next_line
PRINTF_DIR = ft_printf

SRC_DIRS = Converters Checkers List Mem_Handler Printers Str_Handler Str_Modifiers Math

SRC = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJ = $(SRC:.c=.o)

GNL_SRC = $(wildcard $(GNL_DIR)/*.c)
GNL_OBJ = $(GNL_SRC:.c=.o)

PRINTF_LIB = $(PRINTF_DIR)/ft_printf.a

INCLUDES = -I. -I $(GNL_DIR) -I $(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJ)	$(GNL_OBJ) $(PRINTF_LIB)
	ar rcs $(NAME) $(OBJ) $(GNL_OBJ)
	ranlib $(NAME)
	ar x $(PRINTF_LIB)
	ar rcs $(NAME) *.o
	rm -f *.o

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

%.o: %.c libft.h $(GNL_DIR)/get_next_line.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re