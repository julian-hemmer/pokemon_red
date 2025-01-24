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

    sfRenderWindow_clear(window, sfRed);
    sfRenderWindow_display(window);
}

static void update(game_info_t *game_info, delta_t *)
{
    sfRenderWindow *window = game_info->window;
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        process_csfml_event(game_info, event);
}

void handle(game_info_t *game_info, event_data_t *)
{
    LOG_INFO(game_info, "MOUSE RELEASED AT []");
}

int launch_game(game_info_t *game_info)
{
    delta_t delta = create_delta(1.0);

    register_handler(game_info, (event_handler_info_t){
        NORMAL, MOUSE_RELEASED, GAME, true, &handle
    });
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
