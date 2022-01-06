# willcard = prend tout les fichiers *.c (variable propre au Makefile)
SRCS = $(wildcard *.c)
# OBJS = variable SRC modifiee avec .o au lieu de .c comme extension
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXEC = push_swap

all : $(EXEC)

# %.o : %.c = Toutes les cibles *.o seront creees avec les dependances *.c
# raccourci = .c.o comme nom de regle
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

