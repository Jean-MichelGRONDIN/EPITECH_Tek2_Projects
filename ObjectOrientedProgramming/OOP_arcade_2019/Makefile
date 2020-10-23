##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_SFML_DIR	=	lib/src_sfml/

SRC_NCURS_DIR	=	lib/src_ncurs/

SRC_SDL_DIR	=	lib/src_sdl/

SRC_NIBBLER_DIR	=	games/nibbler/

SRC_SOLARFOX_DIR	=	games/solarfox/

SRC_MENU_DIR	=	games/menu/


SRC_SDL	=	$(SRC_SDL_DIR)libSdl.cpp	\
			$(SRC_SDL_DIR)sdlObject.cpp

SRC_SFML	=	$(SRC_SFML_DIR)libSfml.cpp	\
				$(SRC_SFML_DIR)sfmlObject.cpp

SRC_NCURS	=	$(SRC_NCURS_DIR)libNcurs.cpp	\
				$(SRC_NCURS_DIR)ncursObject.cpp

SRC_NIBBLER	=	$(SRC_NIBBLER_DIR)gameNibbler.cpp

SRC_SOLARFOX	=	$(SRC_SOLARFOX_DIR)gameSolarFox.cpp

SRC_MENU	=	$(SRC_MENU_DIR)menu.cpp

SRC_DIR	=	src/

SRC		=	$(SRC_DIR)main.cpp	\
			$(SRC_DIR)core_loop.cpp


DEBUGFLAG	=	-g -g -ggdb

LFLAGS  =   -fpic -shared -lm $(DEBUGFLAG)

CFLAGS  =   -ldl -std=c++17


NAME	=	arcade

NAME1	=	lib_arcade_sdl2.so

NAME2	=	lib_arcade_sfml.so

NAME3	=	lib_arcade_ncurses.so

NAME4	=	lib_arcade_nibbler.so

NAME5	=	menu.so

NAME6	=	lib_arcade_solarfox.so


all:	graphicals games main

core:	main

graphicals:	$(NAME1) $(NAME2) $(NAME3)

games:	$(NAME4) $(NAME5) $(NAME6)

$(NAME1):
	g++ -o $(NAME1) $(SRC_SDL) $(LFLAGS) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
	mv $(NAME1) lib/

$(NAME2):
	g++ -o $(NAME2) $(SRC_SFML) $(LFLAGS)  -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
	mv $(NAME2) lib/

$(NAME3):
	g++ -o $(NAME3) $(SRC_NCURS) $(LFLAGS) -lncurses
	mv $(NAME3) lib/

$(NAME4):
	g++ -o $(NAME4) $(SRC_NIBBLER) $(LFLAGS)
	mv $(NAME4) games/

$(NAME5):
	g++ -o $(NAME5) $(SRC_MENU) $(LFLAGS)
	mv $(NAME5) games/

$(NAME6):
	g++ -o $(NAME6) $(SRC_SOLARFOX) $(LFLAGS)
	mv $(NAME6) games/

main:
	g++ -o $(NAME) $(SRC) $(CFLAGS)

clean:

fclean:	clean
	rm -f lib/$(NAME1)
	rm -f lib/$(NAME2)
	rm -f lib/$(NAME3)
	rm -f games/$(NAME4)
	rm -f games/$(NAME5)
	rm -f games/$(NAME6)
	rm -f $(NAME)

re:	fclean all
