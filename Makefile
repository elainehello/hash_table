NAME = hashtable.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs


SOURCES = ft_putchar.c ft_putstr.c \
ft_ptr_address.c ft_putnbr.c ft_put_unbr.c \
ft_puthex.c ft_printf.c\
parse.c stack.c \

OBJ = $(SOURCES:.c=.o)

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re