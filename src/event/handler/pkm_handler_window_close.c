/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pkm_handler_window_close
*/

#include "pkm_event.h"

void window_close_handler(game_info_t *game_info, event_data_t *)
{
    if (!game_info->running ||
        !sfRenderWindow_isOpen(game_info->window))
        return;
    sfRenderWindow_close(game_info->window);
}
