CC:= cc
CFLAGS:= -Wall -Werror -Wextra

SERVER:= server.c
CLIENT:= client.c parse_pid.c
SERVER_NAME:= server
CLIENT_NAME:= client
SERVER_BONUS:= server_bonus.c
CLIENT_BONUS:= client_bonus.c parse_pid.c
SERVER_NAME_BONUS:= server_bonus
CLIENT_NAME_BONUS:= client_bonus

PRINTF:= ft_printf/libftprintf.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME): $(SERVER) $(PRINTF) 
	$(CC) $(CFLAGS) $(SERVER) $(LIBFT) $(PRINTF) -o $@

$(CLIENT_NAME): $(CLIENT) $(SERVER) $(PRINTF) 
	$(CC) $(CFLAGS) $(CLIENT) $(LIBFT) $(PRINTF) -o $@

$(SERVER_NAME_BONUS): $(SERVER_BONUS) $(PRINTF) 
	$(CC) $(CFLAGS) $(SERVER_BONUS) $(LIBFT) $(PRINTF) -o $@

$(CLIENT_NAME_BONUS): $(CLIENT_BONUS) $(SERVER_BONUS) $(PRINTF) 
	$(CC) $(CFLAGS) $(CLIENT_BONUS) $(LIBFT) $(PRINTF) -o $@

$(PRINTF):
	make -C ft_printf

bonus: $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

clean:
	make clean -C ft_printf

fclean: clean
	make fclean -C ft_printf
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -f $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all
.PHONY: all clean re