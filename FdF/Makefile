CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
SRC = 	wireframe.c utils.c set_map.c rotate.c set_map_utils.c print_wireframe.c print_wireframe_utils.c
OBJ = $(SRC:.c=.o)

# BONUS = 
# SRC_BONUS = 
# OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = Libft_power
LIBFT_A = Libft_power/libft.a

PRINTF = Libft_power/ft_printf
PRINTF_A = Libft_power/ft_printf/ft_printf.a

MLX = minilibx-linux
MLX_A = minilibx-linux/ft_printf.a

INCLUDES = -I Libft_power/ -I minilibx-linux
MLX_LIB = -Lminilibx-linux -lmlx_Linux -L/usr/lib/X11 -lX11 -lXext -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(PRINTF_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT)

$(PRINTF_A):
	make -C $(PRINTF)

$(MLX_A):
	make -C $(MLX)
# bonus: $(BONUS)

# $(BONUS): $(OBJ_BONUS) $(LIBFT_A) $(PRINTF_A)
# 	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_A) $(PRINTF_A) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
# rm -f $(OBJ_BONUS)
	make -C $(LIBFT) clean
	make -C $(PRINTF) clean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
# rm -f $(BONUS)
	make -C $(LIBFT) fclean
	make -C $(PRINTF) fclean
	make -C $(MLX) fclean

re: fclean all
