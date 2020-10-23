##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_DIR	=	./src/

SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)vars_struc_construct_destruct.c	\
		$(SRC_DIR)symbols.c	\
		$(SRC_DIR)format_checkers.c	\
		$(SRC_DIR)prog_loop.c	\
		$(SRC_DIR)register_function.c	\
		$(SRC_DIR)register_function_two.c	\
		$(SRC_DIR)list_functions.c	\
		$(SRC_DIR)ftrace.c

INC	=	-I./include/

CFLAGS	=	$(INC) $(EXTRA_FLAGS) -lelf

EXTRA_FLAGS	=	-W -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	ftrace

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
