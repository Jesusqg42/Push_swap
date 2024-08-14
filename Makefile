NAME = push_swap

SRCS = push_swap.c \
	check_digits.c \
	push_swap_utils.c \
	stack_utils.c \
	instructions.c \


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft.a
LIBFT_PATH = ./libft/

OBJS = ${SRCS:.c=.o}

all: ${NAME} 

${NAME}: ${OBJS} ${LIBFT_PATH}${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_PATH}${LIBFT} -o ${NAME}


${LIBFT_PATH}${LIBFT}:	
			@make -C ${LIBFT_PATH} --silent

clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_PATH}

fclean: clean
	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT}

re: fclean all

.PHONY: all clean fclean re