/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** delta
*/

#include "delta.h"

void update_delta(game_context_t *game_context, delta_t *delta)
{
    double delta_ratio = MICRO_TO_DELTA(
        sfClock_restart(game_context->clock).microseconds);

    delta->original = delta_ratio;
    delta->delta = delta->original * delta->multiplier;
    delta->total_elapsed += delta->delta;
}

delta_t create_delta(double default_multiplier)
{
    delta_t delta = { 0 };

    delta.multiplier = default_multiplier;
    return delta;
}
