/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** string_util
*/

#include "string_util.h"

#include <stdio.h>

int last_index_of(const char *str, char c)
{
    int found = -1;

    for (int i = 0; str[i]; i++) {
        if (str[i] != c)
            continue;
        found = i;
    }
    return found;
}
