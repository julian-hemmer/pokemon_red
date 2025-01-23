/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_processor
*/

#include "pkm_event.h"
#include <SFML/Graphics.h>

void process_csfml_event(
    game_info_t *game_info,
    sfEvent event)
{
    csfml_event_resolver_t resolver;

    for (size_t i = 0; i < CSFML_EVENT_RESOLVER_COUNT; i++) {
        resolver = CSFML_EVENT_RESOLVER[i];
        if (resolver.type != event.type)
            continue;
        resolver.function(game_info, event);
    }
}

void process_event(
    game_info_t *game_info,
    event_data_t *data)
{
    event_handler_t *handler = game_info->handlers;

    while (handler != NULL) {
        if ((data->type != handler->target_event) ||
            (data->is_canceled && handler->ignore_canceled) ||
            (game_info->scene != handler->target_scene)) {
            handler = handler->next_handler;
            continue;
        }
        handler->call_count++;
        handler->handling_function(game_info, data);
        handler = handler->next_handler;
    }
}
