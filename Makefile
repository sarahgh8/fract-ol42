.RECIPEPREFIX = ~
CC = cc
CFLAGS = -Wall -Werror -Wextra 
NAME = fractol
SRC =
OBJ = (SRC:.c=.o)

all : ${NAME}

${NAME}; ${OBJ}
~@ar rcs $@ $<

clean:
~@rm -f ${OBJ}

fclean: clean
~@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
