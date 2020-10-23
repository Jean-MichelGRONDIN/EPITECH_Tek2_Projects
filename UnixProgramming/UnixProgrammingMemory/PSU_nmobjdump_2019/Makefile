##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_1_DIR	=	./src_nm/

SRC_2_DIR	=	./src_objdump/

SRC_1	=	$(SRC_1_DIR)main.c

SRC_2	=	$(SRC_2_DIR)main.c	\
			$(SRC_2_DIR)objdump.c	\
			$(SRC_2_DIR)process_this_file.c	\
			$(SRC_2_DIR)print_header.c	\
			$(SRC_2_DIR)print_header_sixty.c	\
			$(SRC_2_DIR)print_header_thirty.c	\
			$(SRC_2_DIR)print_section.c	\
			$(SRC_2_DIR)print_section_thirty.c

INC	=	-I./include/

CFLAGS	=	$(INC) $(EXTRA_FLAGS)

EXTRA_FLAGS	=	-W -Wall -Wextra -g3 -g -ggdb

OBJ_1	=	$(SRC_1:.c=.o)

OBJ_2	=	$(SRC_2:.c=.o)

CC	=	gcc

NAME_1	=	my_nm

NAME_2	=	my_objdump

all:	$(OBJ_1) $(OBJ_2)
	$(CC) -o $(NAME_1) $(OBJ_1) $(CFLAGS)
	$(CC) -o $(NAME_2) $(OBJ_2) $(CFLAGS)

nm:	$(OBJ_1)
	$(CC) -o $(NAME_1) $(OBJ_1) $(CFLAGS)

objdump:	$(OBJ_2)
	$(CC) -o $(NAME_2) $(OBJ_2) $(CFLAGS)

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_1)
	rm -f $(OBJ_2)
	rm -f vgcore.*
	rm -f *.gc*
	rm -f $(SRC_DIR)*.gc*
	rm -f $(SRC_DIR)vgcore.*
	make -sC ./tests clean

fclean:	clean
	make -sC ./tests fclean
	rm -f $(NAME_1)
	rm -f $(NAME_2)

tests_run:
		make -sC ./tests
		./tests/unit_tests

re:	fclean all

.PHONY:	all	\
	re	\
	clean	\
	fclean	\
	tests_run
