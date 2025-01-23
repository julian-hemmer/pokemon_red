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

static void test(game_info_t *game_info)
{
    register_handler(game_info, (event_handler_info_t){ 0 });
    register_handler(game_info, (event_handler_info_t){ 0 });
    register_handler(game_info, (event_handler_info_t){ 0 });
    dump_event_handler(game_info);
}

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
