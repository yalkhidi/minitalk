CC:= cc
CFLAGS:= -Wall -Werror -Wextra

SERVER:= server.c
CLIENT:= client.c
SERVER_NAME:= server
CLIENT_NAME:= client

LIBFT:= libft/libft.a
PRINTF:= ft_printf/libftprintf.a

all: $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER) $(LIBFT) $(PRINTF) -o $@

$(CLIENT_NAME): server
	$(CC) $(CFLAGS) $(CLIENT) $(LIBFT) $(PRINTF) -o $@

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

clean:
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f server client

re: fclean all
.PHONY: all clean re