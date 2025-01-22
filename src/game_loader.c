/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** game_loader
*/

#include "pokemon.h"
#include "asprintf.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int load_logger(game_info_t *game_info)
{
    char *logger_path = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    my_asprintf(&logger_path, "./log/%02i-%02i-%02.2i.log",
        tm.tm_mon + 1, tm.tm_mday, (tm.tm_year + 1900));
    if (logger_path == 0)
        return 84;
    game_info->logger = init_logger(logger_path);
    free(logger_path);
    return game_info->logger == NULL ? 84 : 0;
}

int load_game(game_info_t *game_info)
{
    if (load_logger(game_info) == 84)
        return 84;
    return 0;
}
