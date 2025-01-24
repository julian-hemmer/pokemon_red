/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** game_loader
*/

#include "pokemon.h"
#include "asprintf.h"
#include "pkm_camera.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>

static int load_window(sfRenderWindow **window)
{
    sfVideoMode video_mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    (*window) = sfRenderWindow_create(video_mode, "Pokemon Red",
        sfResize | sfClose, NULL);
    if (!(*window))
        return 84;
    sfRenderWindow_setFramerateLimit(*window, 144);
    return 0;
}

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

static int load_clock(sfClock **clock)
{
    (*clock) = sfClock_create();
    if ((*clock) == NULL)
        return 84;
    return 0;
}

static int load_camera(
    game_info_t *game_info,
    pkm_camera_t **camera)
{
    vector2f_t default_offset = {
        .x = 0.0, .y = 0.0
    };
    size2f_t default_size = {
        .width = WINDOW_WIDTH,
        .height = WINDOW_HEIGHT
    };

    (*camera) = create_camera(
        game_info, default_offset, default_size);
    if ((*camera) == NULL)
        return 84;
    return 0;
}

int load_game(game_info_t *game_info)
{
    if (load_logger(game_info) == 84 ||
        load_window(&game_info->window) == 84 ||
        load_clock(&game_info->clock) == 84 ||
        load_camera(game_info, &game_info->camera) == 84)
        return 84;
    game_info->scene = GAME;
    return 0;
}
