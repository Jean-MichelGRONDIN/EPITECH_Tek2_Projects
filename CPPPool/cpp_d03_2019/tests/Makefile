##
## EPITECH PROJECT, 2020
## cpp_d03_2019
## File description:
## Makefile
##

SRC_UT	=	./

SRC_DIR	=	../

SRC	=	$(SRC_DIR)init_and_destroy_string.c	\
		$(SRC_DIR)append_s_and_append_c.c	\
		$(SRC_DIR)at_string.c	\
		$(SRC_DIR)c_str_string.c	\
		$(SRC_DIR)clear_string.c	\
		$(SRC_DIR)compare_s_and_compare_c.c	\
		$(SRC_DIR)copy_string.c	\
		$(SRC_DIR)is_empty_string.c	\
		$(SRC_DIR)size_string.c	\
		$(SRC_DIR)assign_s_and_assign_c_string.c	\
		$(SRC_DIR)find_s_and_find_c.c	\
		$(SRC_DIR)insert_s_and_insert_c.c	\
		$(SRC_DIR)to_int_string.c	\
		$(SRC_UT)test_init_and_destroy_string.c	\
		$(SRC_UT)test_assign_s_and_assign_c_string.c	\
		$(SRC_UT)test_at_string.c	\
		$(SRC_UT)test_clear_string.c	\
		$(SRC_UT)test_all_other_functions.c

OBJ	=	$(SRC:.c=.o)

INC	=	-I./../

LDFLAGS	=	-lcriterion -lgcov

EXTRA_FLAGS	=	-std=gnu11 -Wall -Wextra

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