SRCS	= ft_printf.c srcs/ft_itoa_u.c srcs/ft_nbr_tobase.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

HEADER	= includes/ft_printf.h

GCC		= clang

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}:	${OBJS}
				${MAKE} -C ./libft
				cp libft/libft.a ${NAME}
				ar -rcs ${NAME} ${OBJS}
				ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

test:		all
			${GCC} ${CFLAGS} main.c -I ${HEADER} -L. -lftprintf
			./a.out
