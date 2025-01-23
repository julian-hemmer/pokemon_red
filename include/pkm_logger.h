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

void log_info(const logger_t *logger,
    const char *message, ...);

void destroy_logger(logger_t *logger);
logger_t *init_logger(const char *file);

    #define LOG_INFO(g, f...) (log_info(g->logger, f))

#endif /* !LOGGER */
