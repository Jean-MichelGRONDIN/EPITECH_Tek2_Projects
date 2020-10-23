##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_DIR	=	./

SRC	=	$(SRC_DIR)my_strlen.asm	\
		$(SRC_DIR)my_strchr.asm	\
		$(SRC_DIR)my_memset.asm	\
		$(SRC_DIR)my_memcpy.asm	\
		$(SRC_DIR)my_memmove.asm	\
		$(SRC_DIR)my_strcmp.asm	\
		$(SRC_DIR)my_strncmp.asm	\
		$(SRC_DIR)my_rindex.asm	\
		$(SRC_DIR)my_strstr.asm	\
		$(SRC_DIR)my_strcasecmp.asm

OBJ	=	$(SRC:.asm=.o)

NASM	=	nasm

override NASMFLAGS	+=	-f elf64 -Werror

LD	=	ld

LDFLAGS	=	-shared

NAME	=	libasm.so

all: $(OBJ)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJ)

%.o:		%.asm
		$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f vgcore.*
	rm -f *.gc*
	rm -f $(SRC_DIR)*.gc*
	rm -f $(SRC_DIR)vgcore.*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	\
	re	\
	clean	\
	fclean