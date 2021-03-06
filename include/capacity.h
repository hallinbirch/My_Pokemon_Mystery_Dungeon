/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** capacity.h
*/

#ifndef CAPACITY_H_
#define CAPACITY_H_

#include <stddef.h>

enum capacity_category {
	PHYSICAL,
	SPECIAL,
	STATUS
};

typedef struct {
	char *name;
	size_t type;
	size_t category;
	size_t power;
	size_t accuracy;
	size_t pp;
} capacity_t;

#endif
