##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_DIR	=	./src/

PIZZA_DIR = $(SRC_DIR)Pizza/

SRC	=	$(PIZZA_DIR)AbPizza.cpp			\
		$(PIZZA_DIR)Americana.cpp		\
		$(PIZZA_DIR)Fantasia.cpp		\
		$(PIZZA_DIR)Margarita.cpp		\
		$(PIZZA_DIR)Regina.cpp			\
		$(PIZZA_DIR)PizzaFactory.cpp	\
		$(SRC_DIR)Fork.cpp				\
		$(SRC_DIR)Ipc.cpp				\
		$(SRC_DIR)kitchen.cpp			\
		$(SRC_DIR)SigHandler.cpp		\
		$(SRC_DIR)Com.cpp				\
		$(SRC_DIR)Error.cpp				\
		$(SRC_DIR)kitchenManager.cpp	\
		$(SRC_DIR)myClock.cpp			\
		$(SRC_DIR)plazza.cpp			\
		main.cpp

# INC	=	-I./include/

CFLAGS	=	$(EXTRA_FLAGS) -std=c++17 -lpthread # $(INC)

EXTRA_FLAGS	=	-W -Wall -Wextra -g -g3 -ggdb

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

NAME	=	plazza

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o:	%.cpp
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
