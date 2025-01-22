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
    logger_t *logger = init_logger("./log/b.log");
    game_info_t game_info = { 0 };

    log_info(logger, "Test!\n");
    if (load_game(&game_info) != 0) {
        fprintf(stderr, "An error occur while loading the game !\n");
        return 84;
    }
    destroy_logger(logger);
    return 0;
}
