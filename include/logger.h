/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** logger
*/

#ifndef LOGGER
    #define LOGGER

    #include <stdbool.h>
    #include <stdio.h>

typedef struct logger {
    bool enabled;
    bool console_out;
    FILE *file;
} logger_t;

void log_info(const logger_t *config,
    const char *message, ...);

void destroy_logger(logger_t *logger_config);
logger_t *init_logger(const char *file);

#endif /* !LOGGER */
