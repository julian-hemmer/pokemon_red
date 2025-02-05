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

static int load_logger(game_context_t *game_context)
{
    char *logger_path = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    my_asprintf(&logger_path, "./log/%02i-%02i-%02.2i.log",
        tm.tm_mon + 1, tm.tm_mday, (tm.tm_year + 1900));
    if (logger_path == 0)
        return 84;
    game_context->logger = init_logger(logger_path);
    free(logger_path);
    return game_context->logger == NULL ? 84 : 0;
}

static int load_clock(sfClock **clock)
{
    (*clock) = sfClock_create();
    if ((*clock) == NULL)
        return 84;
    return 0;
}

static int load_camera(
    game_context_t *game_context,
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
        game_context, default_offset, default_size);
    if ((*camera) == NULL)
        return 84;
    return 0;
}

static void load_basic_handlers(game_context_t *game_context)
{
    register_handler(game_context, (event_handler_info_t){
        LOWEST, WINDOW_CLOSED, SCENE_ALL, false, &window_close_handler
    });
}

int load_game(game_context_t *game_context)
{
    if (load_logger(game_context) == 84 ||
        load_window(&game_context->window) == 84 ||
        load_clock(&game_context->clock) == 84 ||
        load_camera(game_context, &game_context->camera) == 84)
        return 84;
    game_context->scene = SCENE_GAME;
    load_basic_handlers(game_context);
    return 0;
}
