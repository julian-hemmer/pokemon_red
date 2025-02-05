/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera
*/

#include "pkm_camera.h"
#include "pkm_event.h"

#include <stdlib.h>

static void load_handler(game_context_t *game_context)
{
    register_handler(game_context, (event_handler_info_t){
        NORMAL, PRE_UPDATE, SCENE_GAME, true, &camera_movement_handler
    });
}

pkm_camera_t *create_camera(
    game_context_t *game_context,
    vector2f_t offset,
    size2f_t size)
{
    pkm_camera_t *camera = malloc(sizeof(pkm_camera_t));

    if (camera == NULL)
        return NULL;
    camera->game_context = game_context;
    camera->offset = offset;
    camera->position = (vector2f_t){
        .x = 0.0, .y = 0.0
    };
    camera->size = size;
    load_handler(game_context);
    return camera;
}
