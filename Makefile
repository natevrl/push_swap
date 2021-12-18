SRCS		= rotate_operations.c\
			tracking.c\
			initialisations.c\
			main.c\
			swap_n_push_operations.c\

LIBS		= libft/libft.a

OBJS		= ${SRCS:.c=.o}


NAME		= push_swap

CC			= cc

RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

all:		${NAME} 

${LIBS}:
		cd libft; make

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS} 

clean:	
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all