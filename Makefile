##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## Makefile
##

NAME	=	my_rpg

SRCDIR	=	src/
LIBDIR	=	lib/
GAMEDIR	=	$(SRCDIR)game/
MAPCDIR	=	$(SRCDIR)map_editor/
ANICDIR	=	$(SRCDIR)anime_editor/
MAPDIR	=	$(SRCDIR)map/
ENTDIR	=	$(SRCDIR)entity/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)evt_close.c \
		$(GAMEDIR)game_menu.c \
		$(GAMEDIR)game_loop.c \
		$(MAPCDIR)map_editor_menu.c \
		$(MAPCDIR)map_editor_loop.c \
		$(ANICDIR)anime_editor_menu.c \
		$(ANICDIR)anime_editor_loop.c \
		$(MAPDIR)map_create.c \
		$(MAPDIR)map_resize.c \
		$(MAPDIR)map_destroy.c \
		$(MAPDIR)map_aff.c \
		$(ENTDIR)entity_create.c \
		$(ENTDIR)entity_destroy.c \
		$(ENTDIR)entity_set_pos.c \
		$(ENTDIR)entity_move.c \
		$(ENTDIR)entity_aff.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include -g
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-fdiagnostics-color

LDFLAGS	+=	-l c_graph_prog
LDFLAGS	+=	-L $(LIBDIR) -l Tile_map
LDFLAGS	+=	-L $(LIBDIR) -l Anime_tab

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
