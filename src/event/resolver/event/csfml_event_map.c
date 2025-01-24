/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** csfml_event_map
*/

#include "pkm_event.h"

const csfml_event_resolver_t CSFML_EVENT_RESOLVER[] = {
    {sfEvtClosed, &csfml_window_closed_event},
    {sfEvtMouseButtonReleased, &csfml_event_mouse_released},
    {sfEvtMouseButtonPressed, &csfml_event_mouse_pressed}
};

const size_t CSFML_EVENT_RESOLVER_COUNT = sizeof(
    CSFML_EVENT_RESOLVER) / sizeof(csfml_event_resolver_t);
