/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** logger
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "logger.h"
#include "asprintf.h"

static char *format_message(const char *message, va_list list)
{
    char *formatted = 0;
    char *final_message = 0;

    my_asprintf(&formatted, "[INFO] - %s\n", message);
    if (formatted == 0)
        return 0;
    my_asvprintf(&final_message, formatted, list);
    free(formatted);
    return final_message;
}

void log_info(const logger_t *config, const char *message, ...)
{
    va_list list;
    char *final_message = 0;

    if (!config->enabled)
        return;
    va_start(list, message);
    final_message = format_message(message, list);
    if (final_message == 0) {
        va_end(list);
        return;
    }
    if (config->console_out)
        printf(final_message);
    if (config->file != NULL)
        fprintf(config->file, final_message);
    va_end(list);
    free(final_message);
}
