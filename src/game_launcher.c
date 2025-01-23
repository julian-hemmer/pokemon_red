/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** game
*/

#include "pokemon.h"
#include "delta.h"
#include "pkm_event.h"

static void render(game_info_t *game_info)
{
    sfRenderWindow *window = game_info->window;

    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_display(window);
}

static void update(game_info_t *game_info, delta_t *delta)
{
    sfRenderWindow *window = game_info->window;
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        process_csfml_event(game_info, event);
}

int launch_game(game_info_t *game_info)
{
    delta_t delta = create_delta(1.0);

    game_info->running = true;
    sfClock_restart(game_info->clock);
    while (game_info->running) {
        update_delta(game_info, &delta);
        render(game_info);
        update(game_info, &delta);
        if (!sfRenderWindow_isOpen(game_info->window))
            game_info->running = false;
    }
    return 0;
}
