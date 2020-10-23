##
## EPITECH PROJECT, 2020
## cpp_pool_2019
## File description:
## makefile for the project
##

SRC	=	menger.c	\
		main.c

INC	=	-I./

CFLAGS	=	$(INC) $(EXTRA_FLAGS)

EXTRA_FLAGS	=	-std=gnu11 -W -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	\
	re	\
	clean	\
	fclean	\