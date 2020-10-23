##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_DIR	=	./src/

SRC	=	main.c	\
		$(SRC_DIR)strace.c	\
		$(SRC_DIR)register_function.c	\
		$(SRC_DIR)register_function_two.c

INC	=	-I./include/

CFLAGS	=	$(INC) $(EXTRA_FLAGS)

EXTRA_FLAGS	=	-W -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	strace

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.gc*
	rm -f $(SRC_DIR)*.gc*
	rm -f $(SRC_DIR)vgcore.*
	make -sC ./tests clean

fclean:	clean
	make -sC ./tests fclean
	rm -f $(NAME)

tests_run:
		make -sC ./tests
		./tests/unit_tests

re:	fclean all

.PHONY:	all	\
	re	\
	clean	\
	fclean	\
	tests_run
