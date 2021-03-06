/*
** EPITECH PROJECT, 2018
** naration
** File description:
** naration
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "adventure_intro.h"

const char *text_intro_g[] =
{
	"once upon a time in the world of Pokepitech",
	"a young pokemon named absolourdo decided to revenge\nhis childhood\
	made of violence and discrimination",
	"full of anger the little guy went to Gobu the one who bullied\nhim\
	for years and told him that one day he would be able to win\na fight\
	against the bully.",
	"Gobu twice Absolouro's size looked at his victim\nand laugh then turn\
	back leaving Absolourdo in his mediocrity",
	"Absolourdo, decided to find a way to increase his power\nin a little\
	amount of time. He remembered a very old legend he heared when he was\
	a kid.\nAn artifact could make him evolve and become very powerfull.",
	"He went to his grandma, eated a lot and was told\nhe could find the\
	LEGENDARY ULTIMATE ARTIFACT OF THE POWERFULLNESS OF THE GOD\nin dark\
	and unsafe mystery dungeons...",
	NULL
};

const char *text_end_g = "After a long adventure through unsafe mystery\
_dungeons.\nOur friend succeeded in finding\
the LEGENDARY ULTIMATE ARTIFACT OF THE POWERFULLNESS OF THE GOD\n\
and became the most powerfull pokemon in the world of Pokepitech.\
\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
PS : If you want to know what happen after give to us a good mark:)";

char *text_history(size_t button, bool history)
{
	char *str = NULL;

	if (history)
		str = (char *) text_intro_g[button];
	else
		str = (char *) text_end_g;
	return (str);
}

void load_history_text(sfRenderWindow *window, intro_adventure_t *ad_intro,
		size_t len)
{
	sfText_setPosition(ad_intro->text,
	V2F(WINDOW_SIZE.x / len, 20));
	sfRenderWindow_drawText(window, ad_intro->text, NULL);
}

size_t insert_history_text(char *str, intro_adventure_t *ad_intro,
			int *i, bool test)
{
	char *str2 = "";
	char *string = my_strncat(str2, str, *i);
	size_t len = my_strlen(string);

	sfText_setString(ad_intro->text, string);
	free(string);
	test == true ? (*i)++ : 0;
	return (len);
}

void display_history(sfRenderWindow *window, intro_adventure_t *ad_intro,
		size_t button, menu_t *menu)
{
	static int i = 1;
	static bool test = true;
	static size_t tmp = 0;
	char *str = text_history(button, ad_intro->history);

	(str[i] == '\0') ? test = false : 0;
	if (tmp != button) {
		test = true;
		tmp = button;
		i = 1;
	}
	size_t len = insert_history_text(str, ad_intro, &i, test);

	test == false ? sfMusic_stop(menu->sound.sound_effect[4]) : 0;
	len % 3 == 0 && test == true ?
		sfMusic_play(menu->sound.sound_effect[4]) : 0;
	load_history_text(window, ad_intro, len);
}
