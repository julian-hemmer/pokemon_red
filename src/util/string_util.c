/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** string_util
*/

#include "string_util.h"

#include <stdio.h>

char *last_index_of(char const *str, char c)
{
    char *found = NULL;

    for (int i = 0; str[i]; i++) {
        if (str[i] != c)
            continue;
        found = str + i;
    }
    return found;
}
