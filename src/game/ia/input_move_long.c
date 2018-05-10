/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** input_move_long.c
*/

#include "game_resource.h"
#include "tile_name.h"
#include "input.h"

static size_t get_input(map_t *map,
			size_t tab[map->nb_case_x][map->nb_case_y],
			entity_t *info[map->nb_case_x][map->nb_case_y],
			sfIntRect xyij)
{
	size_t input = 0;
	int x = xyij.left;
	int y = xyij.top;
	int i = xyij.width;
	int j = xyij.height;

	if (tab[x + i][y + j] <= tab[x][y])
		if (tab[x + i][y + j] && !info[x + i][y + j]) {
			i == -1 ? input |= LEFT : 0;
			i == 1 ? input |= RIGHT : 0;
			j == -1 ? input |= UP : 0;
			j == 1 ? input |= DOWN : 0;
			return (input |= MOVE);
		}
	return (0);
}

size_t input_move_long(entity_t *entity, map_t *map,
		size_t tab[map->nb_case_x][map->nb_case_y],
		entity_t *info[map->nb_case_x][map->nb_case_y])
{
	size_t input = 0;

	for (int i = -1; !input && i <= 1; i++)
		for (int j = -1; !input && j <= 1; j++) {
			sfIntRect xyij = {entity->pos.x, entity->pos.y, i, j};

			input = get_input(map, tab, info, xyij);
		}
	if (input)
		return (input);
	return (WAIT);
}
