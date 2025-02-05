/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** delta
*/

#ifndef DELTA_H
    #define DELTA_H

    #define MS_PER_SEC 1000
    #define MICRO_PER_MS 1000
    #define MICRO_PER_SEC 1000000

    #define SEC_PER_MS 0.001
    #define MS_PER_MICRO 0.001
    #define SEC_PER_MICRO 0.000001

    #define DELTA_TO_SEC(value) ((double)(value) * MICRO_PER_SEC)
    #define DELTA_TO_MS(value) ((double)(value) * MICRO_PER_MS)

    #define MICRO_TO_DELTA(value) (value * SEC_PER_MICRO)

    #include "pokemon.h"

typedef struct delta {
    double original;
    double delta;
    double multiplier;
    double total_elapsed;
} delta_t;

void update_delta(game_context_t *game_context, delta_t *delta);
delta_t create_delta(double default_multiplier);

#endif /* !DELTA_H */
