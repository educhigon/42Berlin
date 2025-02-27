CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server 
SRC_SERVER = server.c translation.c helpers.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CLIENT = client
SRC_CLIENT = client.c helpers.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIBFT = Libft/libft.a
PRINTF = ft_printf/ft_printf.a
INCLUDES = -I Libft/ -I ft_printf/

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT)

$(LIBFT):
	make -C Libft
	make -C Libft bonus

$(PRINTF):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)
	make -C Libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	make -C Libft fclean
	make -C ft_printf fclean

re: fclean all


