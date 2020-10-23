##
## EPITECH PROJECT, 2020
## cpp_d03_2019
## File description:
## Makefile
##

SRC	=	init_and_destroy_string.c	\
		append_s_and_append_c.c	\
		at_string.c	\
		c_str_string.c	\
		clear_string.c	\
		compare_s_and_compare_c.c	\
		copy_string.c	\
		is_empty_string.c	\
		size_string.c	\
		assign_s_and_assign_c_string.c	\
		find_s_and_find_c.c	\
		insert_s_and_insert_c.c	\
		to_int_string.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-std=gnu11 -W -Wall -Wextra

NAME	=	libstring.a

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

all:		$(NAME)

clean:
		rm -f $(OBJ)
		make -sC ./tests clean
		rm -f vgcore.*
		rm -f *.gc*

fclean:		clean
		make -sC ./tests fclean
		rm -f $(NAME)

re:		fclean all

tests_run:
		make -sC ./tests
		./tests/unit_tests

.PHONY: all	\
		clean	\
		fclean	\
		re	\
		tests_run