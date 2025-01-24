/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** game
*/

#include "pokemon.h"
#include "delta.h"
#include "pkm_event.h"
#include "pkm_camera.h"

static void render(game_info_t *game_info)
{
    sfRenderWindow *window = game_info->window;

    sfRenderWindow_clear(window, sfBlack);
    camera_draw_line(game_info->camera,
        pkm_vector2f(10, 10), pkm_vector2f(100, 100), 20.0);
    sfRenderWindow_display(window);
}

static void update(game_info_t *game_info, delta_t *)
{
    event_data_t pre_update = {
        .event_data = NULL, .is_canceled = false, .type = PRE_UPDATE
    };
    event_data_t post_update = {
        .event_data = NULL, .is_canceled = false, .type = POST_UPDATE
    };
    sfRenderWindow *window = game_info->window;
    sfEvent event;

    process_event(game_info, &pre_update);
    while (sfRenderWindow_pollEvent(window, &event))
        process_csfml_event(game_info, event);
    process_event(game_info, &post_update);
}

int launch_game(game_info_t *game_info)
{
    delta_t delta = create_delta(1.0);

    game_info->running = true;
    game_info->delta = &delta;
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
