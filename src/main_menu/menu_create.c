/*
** EPITECH PROJECT, 2018
** menu_create
** File description:
** menu_create
*/

#include "prototype.h"
#include "main_menu/menu.h"

void pages(menu_t *menu)
{
	for (int i = 0; i < 3; i++) {
		menu->rect[i] = sfRectangleShape_create();
		sfRectangleShape_setFillColor(menu->rect[i], (sfColor) {0, 0, 0, 150});
		sfRectangleShape_setOutlineThickness(menu->rect[i], 10);
		sfRectangleShape_setOutlineColor(menu->rect[i], sfRed);
	}
	sfRectangleShape_setSize(menu->rect[0], (sfVector2f) {400, 620});
	sfRectangleShape_setPosition(menu->rect[0], (sfVector2f) {10, 10});
	sfRectangleShape_setSize(menu->rect[1], (sfVector2f) {400, 400});
	sfRectangleShape_setPosition(menu->rect[1], (sfVector2f) {1920 - 410, 10});
	sfRectangleShape_setSize(menu->rect[2], (sfVector2f) {1100, 200});
	sfRectangleShape_setPosition(menu->rect[2], (sfVector2f) {400, 750});
	menu->rect[3] = sfRectangleShape_create();//tmp
	sfRectangleShape_setSize(menu->rect[3], (sfVector2f) {400, 100});//tmp
	sfRectangleShape_setFillColor(menu->rect[3], (sfColor) {0, 0, 0, 150});//tmp
	sfRectangleShape_setOutlineThickness(menu->rect[3], 3);
	sfRectangleShape_setOutlineColor(menu->rect[3], sfYellow);
}

void text(menu_t *menu)
{
	menu->font = sfFont_createFromFile(FONT);
	for (int i = 0; i < NB_BUTTON; i++)//tmp
		menu->text[i] = sfText_create();
}

menu_t menu_create(void)
{
	menu_t menu;

	pages(&menu);
	text(&menu);
	menu.button = 0;
	menu.tile_map = NULL;
	menu.settings = settings_load("resources/config");
	return (menu);
}
