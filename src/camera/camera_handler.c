/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera_handler
*/

#include "pkm_camera.h"

void camera_movement_handler(game_info_t *game_info, event_data_t *)
{
    double distance =
        CAMERA_MOVEMENT_SPEED * game_info->delta->delta;

    if (sfKeyboard_isKeyPressed(sfKeyW))
        game_info->camera->position.y += distance;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game_info->camera->position.y -= distance;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        game_info->camera->position.x -= distance;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        game_info->camera->position.x += distance;
}
