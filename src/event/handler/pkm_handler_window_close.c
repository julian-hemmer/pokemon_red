/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pkm_handler_window_close
*/

#include "pkm_event.h"

void window_close_handler(game_context_t *game_context, event_data_t *)
{
    if (!game_context->running ||
        !sfRenderWindow_isOpen(game_context->window))
        return;
    sfRenderWindow_close(game_context->window);
}
