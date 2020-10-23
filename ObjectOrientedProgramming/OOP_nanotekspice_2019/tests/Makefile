##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## compiles all tests
##

SRC_UT	=	./

SRC_DIR	=	./../src/

SRC	=	$(SRC_DIR)myPars.cpp	\
		$(SRC_UT)test_myPars.cpp

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

INC	=	-I./../include/

LDFLAGS	=	-lcriterion

EXTRA_FLAGS	=	-W -Wall -Wextra

CFLAGS	=	$(INC) --coverage

NAME	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

%.o:	%.cpp
	g++ $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJ)
		rm -f vgcore.*
		rm -f *.gc*

fclean:		clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all	\
	re	\
	clean	\
	fclean