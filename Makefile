SRCS = $(wildcard *.c)
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

