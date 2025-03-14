CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server 
SRC_SERVER = server.c translation.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CLIENT = client
SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIBFT = Libft_power
LIBFT_A = Libft_power/libft.a
PRINTF = ft_printf
PRINTF_A = ft_printf/ft_printf.a
INCLUDES = -I Libft_power/ -I ft_printf/

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT_A) $(PRINTF_A) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT_A) $(PRINTF_A) -o $(CLIENT)

$(LIBFT_A):
	make -C $(LIBFT)

$(PRINTF_A):
	make -C $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)
	make -C $(LIBFT) clean
	make -C $(PRINTF) clean

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	make -C $(LIBFT) fclean
	make -C $(PRINTF) fclean

re: fclean all


