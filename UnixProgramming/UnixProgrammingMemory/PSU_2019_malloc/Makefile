##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_DIR	=	./src/

SRC	=	$(SRC_DIR)my_malloc.c	\
		$(SRC_DIR)my_free.c	\
		$(SRC_DIR)my_calloc.c	\
		$(SRC_DIR)list_add.c	\
		$(SRC_DIR)new_block.c	\
		$(SRC_DIR)find_ptr_in_list.c	\
		$(SRC_DIR)my_realloc_array.c	\
		$(SRC_DIR)my_realloc.c	\
		$(SRC_DIR)is_already_one_freed.c

INC	=	-I./include/

CFLAGS	=	$(INC) $(EXTRA_FLAGS)

EXTRA_FLAGS	=	-W -Wall -Wextra -fpic -g3 -g -ggdb

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

all:	$(OBJ)
	gcc -shared -o $(NAME) $(OBJ)

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
