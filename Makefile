NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address 

MLX = -framework OpenGL -framework AppKit -lmlx

SRC = $(wildcard *.c) $(wildcard ./Get_next_line/*.c) $(wildcard ./Libft/*.c)

#PRINTF = ./Printf
#PRINTFA = ./Printf/libftprintf.a

SRCO = $(SRC:.c=.o)
#SRCO += $(PRINTFA)
#srco += $(PRINTFA)

all: $(NAME)

${NAME}: ${SRCO} 
	@$(CC) $(CFLAGS) $(SRCO) $(MLX) -o $(NAME)

#Printfmake : $(PRINTF)
#	MAKE -C $(PRINTF)


clean:
#	$(MAKE) -C $(PRINTF) clean
	-rm -rf $(SRCO)
fclean: clean
#	$(MAKE) -C $(PRINTF) fclean
	-rm -rf $(SRCO) $(NAME)

re: fclean all

.PHONY: all clean fclean re Printfmake