/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pokemon
*/

#ifndef POKEMON_H
    #define POKEMON_H

    #include "pkm_logger.h"
    #include "pkm_scene.h"

    #include <SFML/Graphics.h>

    #define WINDOW_HEIGHT 1080
    #define WINDOW_WIDTH 1920

typedef struct game_context {
    sfRenderWindow *window;
    sfClock *clock;
    struct pkm_camera *camera;

    scene_t scene;
    bool running;
    struct delta *delta;

    logger_t *logger;
    struct event_handler *handlers;
} game_context_t;

int load_game(game_context_t *game_context);
int launch_game(game_context_t *game_context);
int destoy_game(game_context_t *game_context);

#endif /* !POKEMON_H */
