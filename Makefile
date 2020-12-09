SRCS	= *.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

HEADER	= includes/*.h

GCC		= clang

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}:	${OBJS}
				${GCC} ${CFLAGS} main.c libft.a
				ar -rc ${NAME} ${OBJS}
				ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all
