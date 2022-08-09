NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = cc

SOURCE = push_swap.c

RM = rm -f


(name):
		$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

all: $(name)

clean:
		$(RM) $(NAME)

fclean:
		$(clean)

re:
		$(fclean)
		$(all)
