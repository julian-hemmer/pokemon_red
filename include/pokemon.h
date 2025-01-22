/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pokemon
*/

#ifndef POKEMON_H
    #define POKEMON_H

    #include "logger.h"

typedef struct game_info {
    char *window_name;

    logger_t *logger;
} game_info_t;

int load_game(game_info_t *game_info);
int destoy_game(game_info_t *game_info);

#endif /* !POKEMON_H */
