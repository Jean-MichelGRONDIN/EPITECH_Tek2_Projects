##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_DIR	=	./src/

SRC	=	$(SRC_DIR)nanotekspice.cpp	\
		$(SRC_DIR)Component.cpp	\
		$(SRC_DIR)Cable.cpp	\
		$(SRC_DIR)and_Comp.cpp	\
		$(SRC_DIR)or_Comp.cpp	\
		$(SRC_DIR)xor_Comp.cpp	\
		$(SRC_DIR)nand_Comp.cpp	\
		$(SRC_DIR)nor_Comp.cpp	\
		$(SRC_DIR)xnor_Comp.cpp	\
		$(SRC_DIR)not_Comp.cpp	\
		$(SRC_DIR)comp4081.cpp	\
		$(SRC_DIR)comp4071.cpp	\
		$(SRC_DIR)comp4011.cpp	\
		$(SRC_DIR)comp4001.cpp	\
		$(SRC_DIR)comp4030.cpp	\
		$(SRC_DIR)comp4069.cpp	\
		$(SRC_DIR)comp4013.cpp	\
		$(SRC_DIR)input_comp.cpp	\
		$(SRC_DIR)output_comp.cpp	\
		$(SRC_DIR)file_circuit.cpp	\
		$(SRC_DIR)launch_with_this_file.cpp	\
		$(SRC_DIR)myPars.cpp	\
		$(SRC_DIR)create_component.cpp	\
		$(SRC_DIR)prog_loop.cpp	\
		$(SRC_DIR)check_arguments.cpp	\
		$(SRC_DIR)prog_simulate.cpp	\
		$(SRC_DIR)MyError.cpp	\
		$(SRC_DIR)check_links.cpp	\
		$(SRC_DIR)clock_comp.cpp	\
		$(SRC_DIR)true_comp.cpp	\
		$(SRC_DIR)false_comp.cpp	\
		main.cpp

INC	=	-I./include/

CFLAGS	=	$(INC) $(EXTRA_FLAGS)

EXTRA_FLAGS	=	-W -Wall -Wextra -g3 -g -ggdb

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

all:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

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
