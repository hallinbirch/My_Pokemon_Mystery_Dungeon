/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** garou_destroy.c
*/

#include <stdlib.h>
#include "game_resource.h"

void garou_destroy(garou_t *garou)
{
	entity_destroy(&garou->player);
	//dungeon_destroy(&garou->dungeon);
}
