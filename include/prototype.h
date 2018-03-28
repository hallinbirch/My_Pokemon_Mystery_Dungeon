/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** prototype.h
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <SFML/Graphics.h>
#include "game.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_BITS_PER_PIXEL 32
#define WINDOW_PARAMS sfFullscreen
#define FRAMERATE_LIMIT 30

int game_menu(void);
int map_editor_menu(void);
int anime_editor_menu(void);
int game_loop(sfRenderWindow *window, game_t *game);
int map_editor_loop(sfRenderWindow *window, map_t *map);
int anime_editor_loop(sfRenderWindow *window, anime_tab_t *anime_tab);
void evt_close(sfEvent *event, sfRenderWindow *window);

#endif
