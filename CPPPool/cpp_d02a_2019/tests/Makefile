##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## compiles all tests
##

SRC_UT	=	./

SRC_DIR	=	../

SRC	=	$(SRC_DIR)double_list_add_elem_at_back.c	\
		$(SRC_DIR)double_list_get_elem_at_position.c	\
		$(SRC_DIR)double_list_del_elem_at_position.c	\
		$(SRC_DIR)double_list_del_elem_at_back.c	\
		$(SRC_DIR)double_list_del_elem_at_front.c	\
		$(SRC_DIR)double_list_add_elem_at_position.c	\
		$(SRC_DIR)double_list_add_elem_at_front.c	\
		$(SRC_DIR)double_list_dump.c	\
		$(SRC_DIR)double_list_is_empty.c	\
		$(SRC_DIR)double_list_get_size.c	\
		$(SRC_UT)tests_ex00.c

OBJ	=	$(SRC:.c=.o)

INC	=	-I./

LDFLAGS	=	-lcriterion -lgcov

EXTRA_FLAGS	=	-W -Wall -Wextra

CFLAGS	=	$(INC) $(EXTRA_FLAGS) --coverage

NAME	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(SRC_DIR)vgcore.*
		rm -f $(SRC_DIR)*.gc*
		rm -f vgcore.*
		rm -f *.gc*

fclean:		clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all		\
		re		\
		clean	\
		fclean