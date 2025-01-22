/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** game_loader
*/

#include "pokemon.h"

static void clean_logger(game_info_t *game_info)
{
    if (game_info->logger == NULL)
        return;
    destroy_logger(game_info->logger);
}

int destoy_game(game_info_t *game_info)
{
    clean_logger(game_info);
    return 0;
}
