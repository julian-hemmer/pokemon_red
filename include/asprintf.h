/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** asprintf
*/

#ifndef ASPRINTF_H
    #define ASPRINTF_H

    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>

int my_asvprintf(char **str, const char *format, va_list args);
int my_asprintf(char **str, const char *format, ...);

#endif /* !ASPRINTF_H */
