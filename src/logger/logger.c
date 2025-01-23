/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** logger
*/

#include "pkm_logger.h"
#include "file_util.h"

#include <stdlib.h>

static FILE *load_file(const char *file_path)
{
    FILE *file;

    if (file_path == NULL)
        return NULL;
    create_file_with_path(file_path);
    file = fopen(file_path, "a");
    if (file == NULL)
        fprintf(stderr, "Unable to open file %s for logger.\n", file_path);
    return file;
}

logger_t *init_logger(const char *file)
{
    logger_t *config = malloc(sizeof(logger_t));

    if (config == NULL) {
        fprintf(stderr, "Unable to load logger.\n");
    }
    config->enabled = true;
    config->console_out = true;
    config->file = load_file(file);
    return config;
}

void destroy_logger(logger_t *logger)
{
    if (logger->file != NULL)
        fclose(logger->file);
    free(logger);
}
