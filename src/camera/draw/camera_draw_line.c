/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera_draw_line
*/

#include "pkm_camera.h"

#include <SFML/Graphics.h>

static void append_vertex(
    sfVertexArray* line,
    double x, double y,
    sfColor color)
{
    sfVertexArray_append(line, (sfVertex){ { x, y }, color });
}

static void set_line_data(
    sfVertexArray* line,
    vector2f_t start_pos,
    vector2f_t end_pos,
    double thickness)
{
    sfVector2f direction = {
        end_pos.x - start_pos.x,
        end_pos.y - start_pos.y
    };
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    sfVector2f normal = { -(direction.y / length), (direction.x / length) };
    sfVector2f of1 =
        { normal.x * thickness / 2, normal.y * thickness / 2 };
    sfVector2f of2 =
        { -(normal.x) * thickness / 2, -(normal.y) * thickness / 2 };

    sfVertexArray_setPrimitiveType(line, sfTriangles);
    append_vertex(line, start_pos.x + of1.x, start_pos.y + of1.y, sfWhite);
    append_vertex(line, start_pos.x + of2.x, start_pos.y + of2.y, sfWhite);
    append_vertex(line, end_pos.x + of1.x, end_pos.y + of1.y, sfWhite);
    append_vertex(line, end_pos.x + of1.x, end_pos.y + of1.y, sfWhite);
    append_vertex(line, start_pos.x + of2.x, start_pos.y + of2.y, sfWhite);
    append_vertex(line, end_pos.x + of2.x, end_pos.y + of2.y, sfWhite);
}

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
    set_line_data(line, start_position, end_position, thickness);
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
}
