.RECIPEPREFIX = ~
CC = cc
CFLAGS = -Wall -Wextra -Werror
AFLAGS = -lmlx -lX11 -lXext -lm
NAME = fractol
SRC = main.c Mandelbrot.c utils.c strmanip.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
~@$(CC) $(CFLAGS) $(OBJ) $(AFLAGS) -o $(NAME)

%.o: %.c
~@$(CC) $(CFLAGS) -c $<

clean:
~@rm -f $(OBJ)

fclean: clean
~@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re