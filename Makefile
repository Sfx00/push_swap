CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = main.c algorithm/sort_operations_p1.c algorithm/sort_operations_p2.c operations/push.c operations/swap.c operations/rotate.c operations/rev_rotate.c \
			set_elements/set_elements.c set_elements/set_ranking.c \
			stack_operations/stack_operations_p1.c stack_operations/stack_operations_p2.c \
			tools/ft_split.c tools/utility.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re