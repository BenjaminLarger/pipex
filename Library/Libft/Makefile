SRC = $(wildcard ft_*.c) ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(wildcard $(OBJ))

fclean: clean
	$(RM) $(NAME)

re: fclean all