/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** garou_create.c
*/

#include "game_resource.h"

garou_t garou_create(char *settings_file_name)
{
	garou_t garou;

	garou.dungeon = dungeon_create();
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
		garou.inventory[i] = NONE;
	garou.settings = settings_load(settings_file_name);
	return (garou);
}
