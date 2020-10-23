##
## EPITECH PROJECT, 2020
## FUN_imageCompressor_2019
## File description:
## Makefile
##

NAME	=	imageCompressor

all:
		stack build --allow-different-user --copy-bins --local-bin-path .
		mv imageCompressor-exe imageCompressor

clean:
		stack clean --allow-different-user

fclean:	clean
		rm -f $(NAME)

re:		clean all

.PHONY:	all clean fclean re