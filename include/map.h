/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>
#include <stddef.h>
#include "error.h"
#include "tile_map.h"
#include "item.h"

// game_macros
#define GAME_ZOOM 200

// code_macros
#define X_MIN (map->pos.x - center.x / map->size.x > 0 ? \
	map->pos.x - center.x / map->size.x : 0)
#define Y_MIN (map->pos.y - center.y / map->size.y > 0 ? \
	map->pos.y - center.y / map->size.y : 0)
#define X_MAX ((win_size.x - center.x) / map->size.x + map->pos.x + 2 < \
	map->nb_case_x ? (win_size.x - center.x) / \
	map->size.x + map->pos.x + 2 : map->nb_case_x)
#define Y_MAX ((win_size.y - center.y) / map->size.y + \
	map->pos.y + 2 < map->nb_case_y ? (win_size.y - center.y) / \
	map->size.y + map->pos.y + 2 : map->nb_case_y)

typedef struct {
	size_t nb_case_x;
	size_t nb_case_y;
	tva_t **tab;
	enum item_e **item;
	sfVector2f size;
	sfVector2f pos;
	char *tile_map_file_name;
	tile_map_t tile_map;
	enum error_e error;
} map_t;

map_t map_create(size_t nb_case_x, size_t nb_case_y, char *tile_map_file_name);
map_t map_copy(map_t *map);
void map_resize(map_t *map, size_t new_nb_case_x, size_t new_nb_case_y);
void map_destroy(map_t *map);
void map_aff(sfRenderWindow *window, map_t *map);
void map_smooth(map_t *map, size_t x, size_t y);
void map_smooth_all(map_t *map);
void map_save(map_t *map, char *file_name);
map_t map_load(char *file_name);
void map_random(map_t *map);
void linking_rooms(map_t *map);

#endif
