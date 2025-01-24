/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** camera
*/

#ifndef PKM_CAMERA_H
    #define PKM_CAMERA_H

    #include "pkm_position.h"

typedef struct pkm_camera {
    vector2f_t offset;
    vector2f_t position;
    size2f_t size;
} pkm_camera_t;

pkm_camera_t *create_camera(
    vector2f_t offset, size2f_t size);

void draw_line(
    pkm_camera_t *camera,
    vector2f_t start_position,
    vector2f_t end_position,
    double thickness);

#endif /* !PKM_CAMERA_H */
