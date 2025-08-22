NAME = libhashtable.a
EXEC = hashtable_test

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs

SRC_DIR = src
INCLUDE = -Iinclude

SOURCES = $(SRC_DIR)/hash_table.c
OBJ = $(SOURCES:.c=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

$(EXEC): main.c $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) main.c -L. -lhashtable -o $(EXEC)

all: $(NAME)

test: $(EXEC)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re test