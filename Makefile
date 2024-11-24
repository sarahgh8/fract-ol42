.RECIPEPREFIX = ~
CC = cc
CFLAGS = -Wall -Wextra -Werror
AFLAGS = -lmlx -lX11 -lXext -lm -LLibft -lft -L Libft/ft_printf -lftprintf
NAME = fractol
SRC = main.c Mandelbrot.c utils.c
LIBFT = Libft/libft.a

all: $(NAME) 

$(NAME): $(LIBFT)
~@$(CC) $(CFLAGS) $(SRC) $(AFLAGS) -o $(NAME)

clean:
~@make -C Libft clean

fclean: clean
~@rm -f $(NAME)
~@make -C Libft fclean

$(LIBFT):
~@make -C Libft

re: fclean all

.PHONY: all clean fclean re