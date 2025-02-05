/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** csfml_event_closed
*/

#include "pkm_event.h"

void csfml_event_mouse_pressed(game_context_t *game_context, sfEvent event)
{
    mouse_pressed_event_t pressed_data = {
        .x = event.mouseButton.x,
        .y = event.mouseButton.y,
        .button = csfml_button_resolver(event.mouseButton.button)
    };
    event_data_t data = {
        .type = MOUSE_PRESSED,
        .is_canceled = false,
        .event_data = &pressed_data
    };

    process_event(game_context, &data);
}
