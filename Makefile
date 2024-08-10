NAME = push_swap

SRCS = push_swap.c \
	check_digits.c \
	push_swap_utils.c \
	stack_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

OBJS = ${SRCS:.c=.o}

all: ${NAME} 

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS} 

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re