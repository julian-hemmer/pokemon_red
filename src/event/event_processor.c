/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_processor
*/

#include "pkm_event.h"
#include <SFML/Graphics.h>

void process_csfml_event(
    game_context_t *game_context,
    sfEvent event)
{
    csfml_event_resolver_t resolver;

    for (size_t i = 0; i < CSFML_EVENT_RESOLVER_COUNT; i++) {
        resolver = CSFML_EVENT_RESOLVER[i];
        if (resolver.type != event.type)
            continue;
        resolver.function(game_context, event);
    }
}

void process_event(
    game_context_t *game_context,
    event_data_t *data)
{
    event_handler_t *handler = game_context->handlers;

    while (handler != NULL) {
        if ((data->type != handler->target_event) ||
            (data->is_canceled && handler->ignore_canceled) ||
            (game_context->scene != handler->target_scene
                && handler->target_scene != SCENE_ALL)) {
            handler = handler->next_handler;
            continue;
        }
        handler->call_count++;
        handler->handling_function(game_context, data);
        handler = handler->next_handler;
    }
}
