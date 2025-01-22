/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** asprintf
*/

#include "asprintf.h"

int my_asvprintf(char **str, const char *format, va_list args)
{
    va_list args_copy;
    int size = 0;

    va_copy(args_copy, args);
    size = vsnprintf(NULL, 0, format, args_copy) + 1;
    va_end(args_copy);
    (*str) = malloc(size);
    if ((*str) == NULL)
        return -1;
    return vsnprintf((*str), size, format, args);
}
