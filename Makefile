NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = cc

SOURCE = push_swap.c

RM = rm -f


$(NAME): libgen
		$(CC) $(CFLAGS) $(SOURCE) libft/libft.a -o $(NAME)

all: $(name)

libgen:
		cd ./libft && make

clean:
		cd ./libft && make clean

fclean:
		$(RM) $(NAME)
		cd ./libft && make fclean

re:		fclean all
