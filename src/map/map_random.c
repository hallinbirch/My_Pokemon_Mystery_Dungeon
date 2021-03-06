/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_random.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "map.h"
#include "tile_name.h"
#include "my.h"

static sfVector2i take_origin(map_t *map, sfVector2i *size)
{
	sfVector2i origin;
	bool test = true;

	while (test) {
		test = false;
		origin.x = RAND_MIN_MAX(5, map->nb_case_x - size->x - 5);
		origin.y = RAND_MIN_MAX(3, map->nb_case_y - size->y - 3);
		for (int x = origin.x; x < origin.x + size->x; x++)
			for (int y = origin.y; y < origin.y + size->y; y++)
				map->tab[x][y].type != WALL ? test = true : 0;
	}
	return (origin);
}

static bool insert_water(map_t *map, size_t x, size_t y)
{
	bool tmp = false;

	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++)
			if (map->tab[x + i][y + j].type == GROUND) {
				map->tab[x + i][y + j].type = WATER;
				tmp = true;
			}
	return (tmp);
}

bool insert_water_loop(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			if (map->tab[i][j].type == WATER
			&& insert_water(map, i, j)) {
					i--;
					j--;
			}
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			if (map->tab[i][j].type == GROUND)
				return (false);
	return (true);
}

void map_random(map_t *map)
{
	size_t area = map->nb_case_x * map->nb_case_y;
	size_t min = (area / 49) * 0.2;
	size_t max = (area / 49) * 0.3;
	size_t nb_room = RAND_MIN_MAX(min, max);

	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			map->tab[i][j] = TVA(0, 0, 0);
	for (size_t num_room = 0; num_room < nb_room; num_room++) {
		sfVector2i size = {rand() % 5 + 5, rand() % 5 + 5};
		sfVector2i origin = take_origin(map, &size);;

		for (int i = origin.x; i < origin.x + size.x; i++)
			for (int j = origin.y; j < origin.y + size.y; j++)
				map->tab[i][j].type = GROUND;
	}
	linking_rooms(map);
	map_smooth_all(map);
}
