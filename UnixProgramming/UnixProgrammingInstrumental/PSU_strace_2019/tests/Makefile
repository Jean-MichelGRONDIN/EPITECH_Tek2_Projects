##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## compiles all tests
##

SRC_UT	=	test_error.c

SRC_DIR	=	./../src/

SRC	= 	$(SRC_DIR)strace.c	\
		$(SRC_DIR)register_function.c	\
		$(SRC_DIR)register_function_two.c	\
		test_error.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

INC	=	-I./../include/

LDFLAGS	=	-lcriterion

EXTRA_FLAGS	=	-W -Wall -Wextra

CFLAGS	=	$(INC) --coverage $(EXTRA_FLAGS)

NAME	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

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