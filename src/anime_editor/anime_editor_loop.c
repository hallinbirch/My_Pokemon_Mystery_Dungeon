/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** anime_game_loop.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"

int anime_editor_loop(sfRenderWindow *window, anime_tab_t *anime_tab)
{
	//sfVector2f pos = {50, 50};
	sfEvent event;

	(void)anime_tab;
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		sfRenderWindow_clear(window, sfBlack);
		//map_aff(window, &game->map, pos);
		sfRenderWindow_display(window);
	}
	return (0);
}
