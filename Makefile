SRCS = algo_functions.c\
		checker_error.c\
		initialisations.c\
		main.c\
		parsing.c\
		rotate_operations.c\
		rotate_operations_ll.c\
		swap_n_push_operations.c\
		tracking.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXEC = push_swap

all : $(EXEC)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBFT)

clean : 
	rm -f $(OBJS)
	make fclean -C libft

fclean : clean
	rm -f $(EXEC)

re : fclean all

