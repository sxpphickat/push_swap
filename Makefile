NAME		= push_swap

SRC			= push_swap.c\
			  ft_conditions.c\
			  ft_movs.c\
			  ft_small.c\
			  op_push.c\
			  op_rev.c\
			  op_rotate.c\
			  op_swap.c\
			  utils.c\
			  utils2.c\
			  f_sort.c\
			  utils4.c\
			  radix.c\
			  radix2.c\
			  ft_free.c

LIB_PATH	= libft/libft.a

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	$(SRC) $(LIB_PATH)
				$(CC) $(CFLAGS) $(SRC) $(LIB_PATH) -o $(NAME)

$(LIB_PATH):
		make -C ./libft

all:		$(NAME)

clean:
		make -C ./libft clean

fclean:
		$(RM) $(NAME)
		make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re
