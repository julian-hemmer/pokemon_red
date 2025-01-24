/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera_draw_line
*/

#include "pkm_camera.h"

#include <SFML/Graphics.h>

void camera_draw_line(
    pkm_camera_t *camera,
    vector2f_t start_position,
    vector2f_t end_position,
    double thickness)
{
    sfRenderWindow *window = camera->game_info->window;
    sfVertexArray* line = sfVertexArray_create();

    start_position = camera_convert_global_position(camera, start_position);
    end_position = camera_convert_global_position(camera, end_position);
    sfVertexArray_setPrimitiveType(line, sfLines);
    sfVertexArray_append(line,
        (sfVertex){pkm_vector2f_to_csfml(start_position), sfWhite});
    sfVertexArray_append(line,
        (sfVertex){pkm_vector2f_to_csfml(end_position), sfWhite});
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
}
