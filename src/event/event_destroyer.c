/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_destroyer
*/

#include "pkm_event.h"

#include <stdlib.h>

static void free_handler(event_handler_t *handler)
{
    free(handler);
}

void destoy_handler(
    game_context_t *game_context,
    event_handler_t *target_handler)
{
    event_handler_t *previous = NULL;
    event_handler_t *handler = game_context->handlers;

    while (handler != NULL) {
        if (target_handler != handler) {
            previous = handler;
            handler = handler->next_handler;
            continue;
        }
        if (previous == NULL)
            game_context->handlers = handler->next_handler;
        else
            previous->next_handler = handler->next_handler;
        free_handler(handler);
        break;
    }
}

void destoy_handlers(game_context_t *game_context)
{
    event_handler_t *handler = game_context->handlers;
    event_handler_t *next_handler = NULL;

    while (handler != NULL) {
        next_handler = handler->next_handler;
        free_handler(handler);
        handler = next_handler;
    }
    game_context->handlers = NULL;
}
