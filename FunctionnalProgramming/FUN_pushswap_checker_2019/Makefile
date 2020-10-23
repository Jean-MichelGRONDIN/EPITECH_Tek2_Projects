##
## EPITECH PROJECT, 2020
## FUN_day2_2019
## File description:
## makefile for the project
##

HS_SRCS	=	main.hs	\
			pushswapchecker.hs	\
			checkargs.hs	\
			allcmds.hs

NAME	=	pushswap_checker

all:
	ghc --make -o $(NAME) $(HS_SRCS)

clean:
	rm -f *.o
	rm -f *.hi

fclean: clean
	rm -f $(NAME)

re:	fclean all