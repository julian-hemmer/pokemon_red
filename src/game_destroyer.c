/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** game_loader
*/

#include "pokemon.h"
#include "pkm_event.h"

static void clean_logger(game_context_t *game_context)
{
    if (game_context->logger == NULL)
        return;
    destroy_logger(game_context->logger);
}

int destoy_game(game_context_t *game_context)
{
    destoy_handlers(game_context);
    clean_logger(game_context);
    sfRenderWindow_destroy(game_context->window);
    return 0;
}
