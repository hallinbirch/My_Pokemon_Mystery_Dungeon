/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_aff.c
*/

#include "map.h"

void map_aff(sfRenderWindow *window, map_t *map, sfVector2f pos)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f center = {win_size.x / 2, win_size.y / 2};
	tile_map_t *tile_map = &map->tile_map;

	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++) {
			sfFloatRect rect;

			rect.left = map->size.x * (i - pos.x) + center.x;
			rect.top = map->size.y * (j - pos.y) + center.y;
			rect.width = map->size.x;
			rect.height = map->size.y;
			tile_map_aff(window, tile_map, map->tab[i][j], rect);
		}
}
