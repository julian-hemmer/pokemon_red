/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** position_float_convertor
*/

#include "pkm_position.h"

vector2f_t pkm_vector2f(double x, double y)
{
    vector2f_t vector2f = {
        .x = x,
        .y = y
    };

    return vector2f;
}

size2f_t pkm_size2f(double width, double height)
{
    size2f_t size2f = {
        .width = width,
        .height = height
    };

    return size2f;
}
