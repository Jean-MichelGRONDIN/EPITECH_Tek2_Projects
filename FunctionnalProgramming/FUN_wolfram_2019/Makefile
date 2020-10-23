##
## EPITECH PROJECT, 2020
## FUN_day2_2019
## File description:
## makefile for the project
##

HS_SRCS	=	main.hs	\
			check_args.hs	\
			launch.hs	\
			rule30.hs	\
			rule90.hs	\
			rule110.hs	\
			print_lines.hs

NAME	=	wolfram

all:
	ghc --make -o $(NAME) $(HS_SRCS)

clean:
	rm -f *.o
	rm -f *.hi

fclean: clean
	rm -f $(NAME)

re:	fclean all