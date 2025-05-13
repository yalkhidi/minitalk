CC:= cc
CCFLAGS:= -Wall -Werror -Wextra

FILES:= ft_printf.c \
		ft_specifiers.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putunsigned.c \
		ft_puthex.c \
		ft_putvoid.c


OFILES:= $(FILES:.c=.o)
HEADER:= ft_printf.h
NAME:= libftprintf.a

all: $(NAME)
%.o: %.c $(HEADER)
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar -crs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

