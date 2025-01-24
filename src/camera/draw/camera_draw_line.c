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
    start_position = camera_convert_global_position(camera, start_position);
    end_position = camera_convert_global_position(camera, end_position);
    sfVertexArray* line = sfVertexArray_create();
    sfVector2f direction = { end_position.x - start_position.x, end_position.y - start_position.y };
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);

    sfVertexArray_setPrimitiveType(line, sfTriangles);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
    sfVector2f normal = { -direction.y, direction.x };
    sfVector2f offset1 = { normal.x * thickness / 2, normal.y * thickness / 2 };
    sfVector2f offset2 = { -normal.x * thickness / 2, -normal.y * thickness / 2 };

    sfVertexArray_append(line, (sfVertex){ { start_position.x + offset1.x, start_position.y + offset1.y }, sfWhite });
    sfVertexArray_append(line, (sfVertex){ { start_position.x + offset2.x, start_position.y + offset2.y }, sfWhite });
    sfVertexArray_append(line, (sfVertex){ { end_position.x + offset1.x, end_position.y + offset1.y }, sfWhite });
    sfVertexArray_append(line, (sfVertex){ { end_position.x + offset1.x, end_position.y + offset1.y }, sfWhite });
    sfVertexArray_append(line, (sfVertex){ { start_position.x + offset2.x, start_position.y + offset2.y }, sfWhite });
    sfVertexArray_append(line, (sfVertex){ { end_position.x + offset2.x, end_position.y + offset2.y }, sfWhite });
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
}
