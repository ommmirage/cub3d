SRC = main.c

OBJ	= ${SRC:.c=.o}

FLAGS = -L minilibx -lmlx -lXext -lX11

all:	$(OBJ)

.c.o:	gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		rm -f $(OBJ)