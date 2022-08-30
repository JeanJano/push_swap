SRCS		= push_swap.c \
			 checker.c \
			 checker1.c \
			 checker2.c \
			 t_push.c \
			 t_push1.c \
			 t_push2.c \
			 t_push3.c \
			 parsing.c \
			 ft_free.c \
			 ft_move.c \
			 ft_move1.c \
			 ft_algo.c \
			 ft_algo_helper.c \
			 ft_algo_helper1.c \
			 ft_calculate_cost.c

NAME		= push_swap

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -g

INCLUDES	= -I libft

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	${OBJS}
			make re -C libft --no-print-directory
			${CC} ${CFLAGS} ${OBJS} -Llibft -lft ${INCLUDES} -o $(NAME)

clean:
			make clean -C libft --no-print-directory
			rm -f ${OBJS}

fclean:		clean
			make fclean -C libft --no-print-directory
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re