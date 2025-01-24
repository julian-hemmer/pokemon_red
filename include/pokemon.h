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
    #include "pkm_camera.h"

    #include <SFML/Graphics.h>

    #define WINDOW_HEIGHT 1080
    #define WINDOW_WIDTH 1920

typedef struct game_info {
    sfRenderWindow *window;
    sfClock *clock;
    pkm_camera_t *camera;

    scene_t scene;
    bool running;

    logger_t *logger;
    struct event_handler *handlers;
} game_info_t;

int load_game(game_info_t *game_info);
int launch_game(game_info_t *game_info);
int destoy_game(game_info_t *game_info);

#endif /* !POKEMON_H */
