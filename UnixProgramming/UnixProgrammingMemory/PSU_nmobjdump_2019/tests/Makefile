##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## compiles all tests
##

SRC_UT	=	./

SRC_DIR	=	./../src/

SRC	=

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

INC	=	-I./../include/

LDFLAGS	=	-lcriterion

EXTRA_FLAGS	=	-W -Wall -Wextra -g3

CFLAGS	=	$(INC) --coverage

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