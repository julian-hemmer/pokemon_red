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

static void render(game_context_t *game_context)
{
    sfRenderWindow *window = game_context->window;

    sfRenderWindow_clear(window, sfBlack);
    camera_draw_line(game_context->camera, (camera_line_t) {
        pkm_vector2f(10, 10), pkm_vector2f(100, 100), 20.0, sfRed
    });
    sfRenderWindow_display(window);
}

static void update(game_context_t *game_context, delta_t *)
{
    event_data_t pre_update = {
        .event_data = NULL, .is_canceled = false, .type = PRE_UPDATE
    };
    event_data_t post_update = {
        .event_data = NULL, .is_canceled = false, .type = POST_UPDATE
    };
    sfRenderWindow *window = game_context->window;
    sfEvent event;

    process_event(game_context, &pre_update);
    while (sfRenderWindow_pollEvent(window, &event))
        process_csfml_event(game_context, event);
    process_event(game_context, &post_update);
}

int launch_game(game_context_t *game_context)
{
    delta_t delta = create_delta(1.0);

    game_context->running = true;
    game_context->delta = &delta;
    sfClock_restart(game_context->clock);
    while (game_context->running) {
        update_delta(game_context, &delta);
        render(game_context);
        update(game_context, &delta);
        if (!sfRenderWindow_isOpen(game_context->window))
            game_context->running = false;
    }
    return 0;
}
