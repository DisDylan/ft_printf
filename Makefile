SRCS	= srcs/ft_atoi.c srcs/ft_itoa.c srcs/ft_putchar.c srcs/ft_putendl.c srcs/ft_putnbr_base.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_strdup.c srcs/ft_strlen.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

HEADER	= ft_printf.h

GCC		= clang

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}:	${OBJS}
				ar -rc ${NAME} ${OBJS}
				ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all