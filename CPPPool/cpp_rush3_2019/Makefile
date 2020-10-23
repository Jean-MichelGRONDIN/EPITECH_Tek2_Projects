##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## makefile for th project
##

SRC_DIR	=	./

OBJECTS_DIR	=	$(SRC_DIR)Objects/

MATERIALS_DIR	=	$(SRC_DIR)Materials/

MAP_DIR	=	$(SRC_DIR)Map/

CHARACTERS_DIR	=	$(SRC_DIR)Characters/

BUILDING_DIR	=	$(SRC_DIR)Buildings/

LOOP_DIR	=	$(SRC_DIR)Loops/

UNIVERSE_DIR	=	$(SRC_DIR)Universe/

R_DIR	=	$(SRC_DIR)Resseources/

CITY_DIR	=$(SRC_DIR)City/

GUI_DIR	=	$(SRC_DIR)Gui/

SRCS	=	$(LOOP_DIR)game_loop.cpp	\
			$(MAP_DIR)Map.cpp	\
			$(UNIVERSE_DIR)universe.cpp	\
			$(UNIVERSE_DIR)game.cpp	\
			$(R_DIR)Tree.cpp \
			$(R_DIR)Ressoureces.cpp \
			$(CHARACTERS_DIR)Character.cpp	\
			$(CHARACTERS_DIR)Player.cpp	\
			$(OBJECTS_DIR)Object.cpp	\
			$(OBJECTS_DIR)PickAxe.cpp	\
			$(GUI_DIR)ProgressBar.cpp	\
			$(GUI_DIR)ObjectSlot.cpp	\
			$(BUILDING_DIR)Building.cpp	\
			$(BUILDING_DIR)LittleBuilding.cpp	\
			$(BUILDING_DIR)MiddleBuilding.cpp	\
			$(BUILDING_DIR)BigBuilding.cpp	\
			$(MATERIALS_DIR)Materials.cpp	\
			$(MATERIALS_DIR)Wood.cpp	\
			$(MATERIALS_DIR)Rock.cpp	\
			$(MATERIALS_DIR)Iron.cpp	\
			$(CITY_DIR)City.cpp \
			$(CHARACTERS_DIR)Pnj.cpp \
			$(CHARACTERS_DIR)Forgeron.cpp	\
			$(CHARACTERS_DIR)Bucheron.cpp	\
			$(CHARACTERS_DIR)Mineur.cpp	\
			main.cpp

CFLAGS	=	$(INC) $(LIB) $(EXTRA_FLAGS) $(G_FLAGS)

G_FLAGS	=	-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -g3

EXTRA_FLAGS	=	-W -Wall -Wextra

NAME	=	rpg_oui

all:
	g++ -o $(NAME) $(SRCS) $(CFLAGS)

clean:
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