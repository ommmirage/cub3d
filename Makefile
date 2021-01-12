SRC = main.c

OBJ	= ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	$(OBJ)

.c.o:	gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		rm -f $(OBJ)