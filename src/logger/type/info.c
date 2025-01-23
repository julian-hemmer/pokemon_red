/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** logger
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include <time.h>

#include "pkm_logger.h"
#include "asprintf.h"

static char *format_message(const char *message, va_list list)
{
    char *formatted = 0;
    char *final_message = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    my_asprintf(&formatted, "[%02.2i:%02.2i:%02.2i] - [INFO]"
        " - %s\n", tm.tm_hour, tm.tm_min, tm.tm_sec, message);
    if (formatted == 0)
        return 0;
    my_asvprintf(&final_message, formatted, list);
    free(formatted);
    return final_message;
}

void log_info(const logger_t *logger, const char *message, ...)
{
    va_list list;
    char *final_message = 0;

    if (!logger->enabled)
        return;
    va_start(list, message);
    final_message = format_message(message, list);
    if (final_message == 0) {
        va_end(list);
        return;
    }
    if (logger->console_out)
        printf("%s", final_message);
    if (logger->file != NULL)
        fprintf(logger->file, "%s", final_message);
    va_end(list);
    free(final_message);
}
