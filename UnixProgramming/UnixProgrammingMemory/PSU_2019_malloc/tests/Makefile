##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## compiles all tests
##

SRC_UT	=	./

SRC_DIR	=	./../src/

SRC	=	$(SRC_UT)test_my_malloc.c	\
		$(SRC_UT)test_my_free.c

OBJ	=	$(SRC:.c=.o)

INC	=	-I./../include/

LIB	=	-L./../ -lmy_malloc

LDFLAGS	=	$(LIB) -lcriterion -lgcov

EXTRA_FLAGS	=	-W -Wall -Wextra -g3

CFLAGS	=	$(INC) $(EXTRA_FLAGS) --coverage

NAME	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)
		rm -f vgcore.*
		rm -f *.gc*

fclean:		clean
		rm -f $(NAME)

re:	fclean all
