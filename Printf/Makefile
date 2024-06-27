NAME = libftprintf.a 
CC = cc
CFLAGS = -Wall -Wextra -Werror
FUN =	ft_printf.c \
		ft_putunsigned_len.c \
		ft_putstr_len.c \
		ft_putptr_len.c \
		ft_putnbr_len.c \
		ft_puthex_len.c \
		ft_putchar_len.c \
		ft_itoa.c \
		ft_strlen.c \
		ft_itoa.c \
		ft_strlen.c

FUNO = $(FUN:.c=.o)

all : $(NAME)

$(NAME): $(FUNO)
	ar -rcs $(NAME) $(FUNO)

clean: 
	-rm -rf $(FUNO)

fclean: 
	-rm -rf $(NAME) $(FUNO)

re: fclean all

.PHONY: all clean fclean re
