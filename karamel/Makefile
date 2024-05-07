NAME = minik

CC = cc
CFLAGS = -Wall -Wextra -Werror

FILE = ml.c

MLX = -framework OpenGL -framework AppKit -lmlx

FILEO = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(FILEO)
	@$(CC) $(CFLAGS) $(FILEO) $(MLX) -o $(NAME)

fclean:
	-rm -rf $(FILEO) $(NAME)

re: fclean all

.PHONY: all fclean 