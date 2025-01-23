/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** main
*/

#include <stdio.h>

#include "pokemon.h"
#include "pkm_logger.h"
#include "pkm_event.h"

int main(int, const char **)
{
    game_info_t game_info = { 0 };

    if (load_game(&game_info) != 0) {
        fprintf(stderr, "An error occur while loading the game !\n");
        destoy_game(&game_info);
        return 84;
    }
    test(&game_info);
    destoy_game(&game_info);
    return 0;
}
