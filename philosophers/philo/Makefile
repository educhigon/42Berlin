CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRC_DIRS = ../philo

SRC = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJ = $(SRC:.c=.o)

# BONUS = 
# SRC_BONUS = 
# OBJ_BONUS = $(SRC_BONUS:.c=.o)

# LIBFT = Libft_power
# LIBFT_A = Libft_power/libft.a

# PRINTF = Libft_power/ft_printf
# PRINTF_A = Libft_power/ft_printf/ft_printf.a

# INCLUDES = -I Libft_power/ -I ft_printf/

all: $(NAME)

$(NAME): $(OBJ) #$(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# $(LIBFT_A):
# 	make -C $(LIBFT)

# $(PRINTF_A):
# 	make -C $(PRINTF)

# bonus: $(BONUS)

# $(BONUS): $(OBJ_BONUS) $(LIBFT_A) $(PRINTF_A)
# 	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_A) $(PRINTF_A) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
# rm -f $(OBJ_BONUS)
# make -C $(LIBFT) clean
# make -C $(PRINTF) clean

fclean: clean
	rm -f $(NAME)
# rm -f $(BONUS)
# make -C $(LIBFT) fclean
# make -C $(PRINTF) fclean

re: fclean all
