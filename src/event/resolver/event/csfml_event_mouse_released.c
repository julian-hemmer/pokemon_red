/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** csfml_event_closed
*/

#include "pkm_event.h"

void csfml_event_mouse_released(game_context_t *game_context, sfEvent event)
{
    mouse_released_event_t released_data = {
        .x = event.mouseButton.x,
        .y = event.mouseButton.y,
        .button = csfml_button_resolver(event.mouseButton.button)
    };
    event_data_t data = {
        .type = MOUSE_RELEASED,
        .is_canceled = false,
        .event_data = &released_data
    };

    process_event(game_context, &data);
}
