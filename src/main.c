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
    game_context_t game_context = { 0 };

    if (load_game(&game_context) != 0) {
        fprintf(stderr, "An error occur while loading the game !\n");
        destoy_game(&game_context);
        return 84;
    }
    launch_game(&game_context);
    destoy_game(&game_context);
    return 0;
}
