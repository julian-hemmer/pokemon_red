/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera_handler
*/

#include "pkm_camera.h"

void camera_movement_handler(game_context_t *game_context, event_data_t *)
{
    double distance =
        CAMERA_MOVEMENT_SPEED * game_context->delta->delta;

    if (sfKeyboard_isKeyPressed(sfKeyW))
        game_context->camera->position.y += distance;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game_context->camera->position.y -= distance;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        game_context->camera->position.x -= distance;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        game_context->camera->position.x += distance;
}
