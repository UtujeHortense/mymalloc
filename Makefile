##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile ex01
##


SRC	=	my_malloc.c	\
		power_of_2.c \
		check_space.c \
		other_alloc.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

CFLAGS	+=	-Wall -Wextra -I./include -fPIC

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -shared -o $(NAME) $(OBJ)

clean:
	rm -f *~
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
