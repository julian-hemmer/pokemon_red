/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** asprintf
*/

#include "asprintf.h"

int my_asprintf(char **str, const char *format, ...)
{
    va_list args;
    int size = 0;

    va_start(args, format);
    size = my_asvprintf(str, format, args);
    va_end(args);
    return size;
}
