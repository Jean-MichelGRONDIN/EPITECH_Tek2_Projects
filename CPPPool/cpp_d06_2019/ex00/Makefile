##
## EPITECH PROJECT, 2020
## cpp_pool_2019
## File description:
## makefile for the project
##

SRC	=	main.cpp

INC	=	-I./

CFLAGS	=	$(INC) $(EXTRA_FLAGS)

EXTRA_FLAGS	=	-Wall -Wextra -Werror

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_cat

all:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

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
	fclean