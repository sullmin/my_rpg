##
## EPITECH PROJECT, 2020
## Project_2020
## File description:
## Project makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	exec.out

CFLAGS	+= -Wall -Wextra -W -Werror -I./include

all:	$(NAME)

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

lib:
	make -C ./lib/my

libre:
	make re -C ./lib/my

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

reall:	fclean all libre

#tests_run:
#gcc -o $(NAME) $(SRC_UT) -I./include -L./lib/my -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re
