/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera
*/

#include "pkm_camera.h"
#include "pkm_event.h"

#include <stdlib.h>

static void load_handler(game_info_t *game_info)
{
    register_handler(game_info, (event_handler_info_t){
        NORMAL, PRE_UPDATE, GAME, true, &camera_movement_handler
    });
}

pkm_camera_t *create_camera(
    game_info_t *game_info,
    vector2f_t offset,
    size2f_t size)
{
    pkm_camera_t *camera = malloc(sizeof(pkm_camera_t));

    if (camera == NULL)
        return NULL;
    camera->game_info = game_info;
    camera->offset = offset;
    camera->position = (vector2f_t){
        .x = 0.0, .y = 0.0
    };
    camera->size = size;
    load_handler(game_info);
    return camera;
}
