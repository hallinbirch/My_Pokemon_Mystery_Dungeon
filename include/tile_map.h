/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map.h
*/

#ifndef TILE_MAP_H_
#define TILE_MAP_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <stddef.h>
#include "error.h"

#define TVA(type, var, alt) (tva_t) {type, var, alt}

#ifndef RECTEX_T_
#define RECTEX_T_

typedef struct {
	size_t texture_num;
	sfIntRect rect;
} rectex_t;

#endif

typedef struct {
	size_t type;
	size_t var;
	size_t alt;
} tva_t;

typedef struct {
	size_t nb_texture;
	sfTexture **texture;
	size_t nb_type;
	size_t *nb_var;
	size_t **nb_alt;
	rectex_t ***rectex;
	sfSprite *sprite;
	enum error_e error;
} tile_map_t;

tile_map_t tile_map_create(void);
tile_map_t tile_map_create_from_file(char *file_name);
tile_map_t tile_map_create_from_fd(int fd);
void tile_map_destroy(tile_map_t *tile_map);
void tile_map_aff(sfRenderWindow *window, tile_map_t *tile_map,
		tva_t tva, sfFloatRect rect);
bool error_map5(tile_map_t *tile_map, int fd, size_t i);
#endif
