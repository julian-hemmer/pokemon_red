/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera_draw_line
*/

#include "pkm_camera.h"

#include <SFML/Graphics.h>
#include <math.h>

static void append_vertex(
    sfVertexArray* line,
    double x, double y,
    sfColor color)
{
    sfVertexArray_append(line, (sfVertex){ { x, y }, color, { 0, 0 } });
}

static void set_line_data(
    sfVertexArray* vline, camera_line_t line)
{
    sfColor color = line.color;
    vector2f_t end_pos = line.end_position;
    vector2f_t start_pos = line.start_position;
    sfVector2f direction = {
        end_pos.x - start_pos.x, end_pos.y - start_pos.y
    };
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    sfVector2f normal = { -(direction.y / length), (direction.x / length) };
    sfVector2f of1 =
        { normal.x * line.thickness / 2, normal.y * line.thickness / 2 };
    sfVector2f of2 =
        { -(normal.x) * line.thickness / 2, -(normal.y) * line.thickness / 2 };

    sfVertexArray_setPrimitiveType(vline, sfTriangles);
    append_vertex(vline, start_pos.x + of1.x, start_pos.y + of1.y, color);
    append_vertex(vline, start_pos.x + of2.x, start_pos.y + of2.y, color);
    append_vertex(vline, end_pos.x + of1.x, end_pos.y + of1.y, color);
    append_vertex(vline, end_pos.x + of1.x, end_pos.y + of1.y, color);
    append_vertex(vline, start_pos.x + of2.x, start_pos.y + of2.y, color);
    append_vertex(vline, end_pos.x + of2.x, end_pos.y + of2.y, color);
}

void camera_draw_line(
    pkm_camera_t *camera,
    camera_line_t line)
{
    sfRenderWindow *window = camera->game_context->window;
    sfVertexArray* vertex_line = sfVertexArray_create();

    line.start_position =
        camera_convert_global_position(camera, line.start_position);
    line.end_position =
        camera_convert_global_position(camera, line.end_position);
    set_line_data(vertex_line, line);
    sfRenderWindow_drawVertexArray(window, vertex_line, NULL);
    sfVertexArray_destroy(vertex_line);
}
