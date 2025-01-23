/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_registor
*/

#include "pkm_event.h"

#include <stdlib.h>

static void transfer_data(
    event_handler_t *new_handler,
    event_handler_info_t handler_info)
{
    new_handler->handling_function = handler_info.handling_function;
    new_handler->priority = handler_info.priority;
    new_handler->target_event = handler_info.target_event;
    new_handler->target_scene = handler_info.target_scene;
}

event_handler_creation_t register_handler(
    game_info_t *game_info,
    event_handler_info_t handler_info)
{
    event_handler_creation_t creation_data = { 0 };
    event_handler_t *new_handler = malloc(sizeof(event_handler_t));

    creation_data.handler = new_handler;
    if (new_handler == NULL) {
        creation_data.has_succed = false;
        return creation_data;
    }
    transfer_data(new_handler, handler_info);
    new_handler->next_handler = game_info->handlers;
    game_info->handlers = new_handler;
    return creation_data;
}
