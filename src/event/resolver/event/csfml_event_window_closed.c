/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** csfml_event_closed
*/

#include "pkm_event.h"

void csfml_window_closed_event(game_context_t *game_context, sfEvent)
{
    event_data_t data = {
        .type = WINDOW_CLOSED,
        .is_canceled = false,
        .event_data = NULL
    };

    process_event(game_context, &data);
}
