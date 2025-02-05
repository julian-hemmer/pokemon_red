/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_dumper
*/

#include "pkm_event.h"
#include "pkm_logger.h"

#include <stdint.h>

void dump_event_handler(game_context_t *game_context)
{
    event_handler_t *handlers = game_context->handlers;

    LOG_INFO(game_context, "<EventHandlerDump>");
    for (uint64_t i = 0; handlers != NULL; i++) {
        LOG_INFO(game_context, "[%i] Type[%i] | "
            "Priority[%i] | Scene[%i] | "
            "CallCount[%i] | IgnoreCanceled[%i].",
            i, handlers->target_event,
            handlers->priority, handlers->target_scene,
            handlers->call_count, handlers->ignore_canceled);
        handlers = handlers->next_handler;
    }
    LOG_INFO(game_context, "</EventHandlerDump>");
}
