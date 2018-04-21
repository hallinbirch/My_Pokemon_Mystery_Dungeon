/*
** EPITECH PROJECT, 2018
** map_options
** File description:
** map_optios
*/

#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "prototype.h"
#include "my.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"
#include "option_map_editor.h"

void choice_cursor(option_editor_t *option, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;

	sfText_setString(option->choice[0], "MAP TYPE");
	sfText_setString(option->choice[1], "MAP HEIGHT");
	sfText_setString(option->choice[2], "MAP WIDTH");
	for (size_t i = 0; i < 3; i++) {
		sfText_setPosition(option->choice[i], (sfVector2f) {WINDOW_SIZE.x / 2 - 300, pos_y});
		sfText_setColor(option->choice[i], (sfColor){250, 250, 0,
					option->choice_curs == i ? 255 : 180});
		sfRenderWindow_drawText(window, option->choice[i], NULL);
		pos_y += 100;
	}
}

void display_options_editor(option_editor_t *option, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, option->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, option->back, NULL);
	choice_cursor(option, window);
	sfRenderWindow_drawText(window, option->text[option->nb_tile], NULL);
	sfRenderWindow_drawText(window, option->size_map_x, NULL);
	sfRenderWindow_drawText(window, option->size_map_y, NULL);
}

void param_map(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	sfEvent event;
	option_editor_t option = option_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
			move_curseur_option_editor(&option, &event);
			size_tile_map_x(&event, window, &option);
			size_tile_map_y(&event, window, &option);
			map_resize(map, option.size_x, option.size_y);
			change_tile_map(window, &option, &event);
			menu->tile_map[0] = tile_map_create_from_file(TILEFILE);
			map->tile_map = &menu->tile_map[0];//tmp
		}
		sfRenderWindow_clear(window, sfBlack);
		display_options_editor(&option, window);
		sfRenderWindow_display(window);
	}
}
