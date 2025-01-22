/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** main
*/

#include <stdio.h>

#include "pokemon.h"
#include "logger.h"

int main(int, const char **)
{
    game_info_t game_info = { 0 };

    if (load_game(&game_info) != 0) {
        fprintf(stderr, "An error occur while loading the game !\n");
        destoy_game(&game_info);
        return 84;
    }
    log_info(game_info.logger, "Papa et mes %i chips !", 5);
    destoy_game(&game_info);
    return 0;
}
