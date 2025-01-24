/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** csfml_button_map
*/

#include "pkm_event.h"

const csfml_button_resolver_t CSFML_BUTTON_RESOLVER[] = {
    {sfMouseLeft, BUTTON_LEFT},
};

const size_t CSFML_BUTTON_RESOLVER_COUNT = sizeof(
    CSFML_BUTTON_RESOLVER) / sizeof(csfml_button_resolver_t);

mouse_button_t csfml_button_resolver(sfMouseButton button)
{
    csfml_button_resolver_t resolver;

    for (size_t i = 0; i < CSFML_BUTTON_RESOLVER_COUNT; i++) {
        resolver = CSFML_BUTTON_RESOLVER[i];
        if (resolver.csfmlButton != button)
            continue;
        return resolver.pkmButton;
    }
    return -1;
}

sfMouseButton pkm_button_resolver(mouse_button_t button)
{
    csfml_button_resolver_t resolver;

    for (size_t i = 0; i < CSFML_BUTTON_RESOLVER_COUNT; i++) {
        resolver = CSFML_BUTTON_RESOLVER[i];
        if (resolver.pkmButton != button)
            continue;
        return resolver.csfmlButton;
    }
    return -1;
}
