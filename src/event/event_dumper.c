/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_dumper
*/

#include "pkm_event.h"
#include "pkm_logger.h"

#include <stdint.h>

void dump_event_handler(game_info_t *game_info)
{
    event_handler_t *handlers = game_info->handlers;

    LOG_INFO(game_info, "<EventHandlerDump>");
    for (uint64_t i = 0; handlers != NULL; i++) {
        LOG_INFO(game_info, "[%i] Type[%i] | Priority[%i] | Scene[%i].",
            i, handlers->target_event,
            handlers->priority, handlers->target_scene);
        handlers = handlers->next_handler;
    }
    LOG_INFO(game_info, "</EventHandlerDump>");
}
