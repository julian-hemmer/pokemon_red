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

typedef struct game_info {
    sfRenderWindow *window;

    scene_t scene;

    logger_t *logger;
    struct event_handler *handlers;
} game_info_t;

int load_game(game_info_t *game_info);
int destoy_game(game_info_t *game_info);

#endif /* !POKEMON_H */
