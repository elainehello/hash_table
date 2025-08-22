NAME = hashtable.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs

SRC_DIR = src
INCLUDE = -Iinclude

SOURCES = $(SRC_DIR)/hash_table.c
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