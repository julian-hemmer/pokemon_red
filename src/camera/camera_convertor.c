/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera_convertor
*/

#include "pkm_position.h"
#include "pkm_camera.h"

vector2f_t camera_convert_global_position(
    pkm_camera_t *camera, vector2f_t global_position)
{
    vector2f_t local_position = {
        .x = 0.0,
        .y = 0.0
    };

    local_position.x = global_position.x - camera->position.x;
    local_position.y = global_position.y - camera->position.y;
    return local_position;
}

vector2f_t camera_convert_local_position(
    pkm_camera_t *camera, vector2f_t local_position)
{
    vector2f_t global_position = {
        .x = 0.0,
        .y = 0.0
    };

    global_position.x = local_position.x + camera->position.x;
    global_position.y = local_position.y + camera->position.y;
    return global_position;
}
