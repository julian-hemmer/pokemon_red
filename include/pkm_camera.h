/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera
*/

#ifndef PKM_CAMERA_H
    #define PKM_CAMERA_H

    #include "pkm_position.h"
    #include "pkm_event.h"
    #include "pkm_logger.h"
    #include "pokemon.h"
    #include "delta.h"

    #define CAMERA_MOVEMENT_SPEED 100

typedef struct pkm_camera {
    game_context_t *game_context;
    vector2f_t offset;
    vector2f_t position;
    size2f_t size;
} pkm_camera_t;

pkm_camera_t *create_camera(
    game_context_t *game_context,
    vector2f_t offset,
    size2f_t size);

vector2f_t camera_convert_global_position(
    pkm_camera_t *camera, vector2f_t global_position);
vector2f_t camera_convert_local_position(
    pkm_camera_t *camera, vector2f_t local_position);

typedef struct {
    vector2f_t start_position;
    vector2f_t end_position;
    double thickness;
    sfColor color;
} camera_line_t;

void camera_draw_line(
    pkm_camera_t *camera,
    camera_line_t line);

void camera_movement_handler(game_context_t *game_context, event_data_t *);

#endif /* !PKM_CAMERA_H */
