/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera
*/

#include "pkm_camera.h"

#include <stdlib.h>

pkm_camera_t *create_camera(
    vector2f_t offset, size2f_t size)
{
    pkm_camera_t *camera = malloc(sizeof(pkm_camera_t));

    camera->offset = offset;
    camera->position = (vector2f_t){
        .x = 0.0, .y = 0.0
    };
    camera->size = size;
    return camera;
}
