/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** logger
*/

#include <stdio.h>
#include <stdarg.h>

#include "logger.h"

void log_info(const logger_t *config, const char *message, ...)
{
    va_list list;

    if (!config->enabled)
        return;
    va_start(list, message);
    if (config->console_out)
        vprintf(message, list);
    if (config->file != NULL)
        vfprintf(config->file, message, list);
    va_end(list);
}
