/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** position_float_convertor
*/

#include "pkm_position.h"

sfVector2f pkm_vector2f_to_csfml(vector2f_t pkm_vector2f)
{
    sfVector2f csfml_vector2f = {
        .x = pkm_vector2f.x,
        .y = pkm_vector2f.y
    };

    return csfml_vector2f;
}

sfVector2f pkm_size2f_to_csfml(size2f_t pkm_size2f)
{
    sfVector2f csfml_vector2f = {
        .x = pkm_size2f.width,
        .y = pkm_size2f.height
    };

    return csfml_vector2f;
}

vector2f_t csfml_vector2f_to_pkm(sfVector2f csfml_vector2f)
{
    vector2f_t pkm_vector2f = {
        .x = csfml_vector2f.x,
        .y = csfml_vector2f.y
    };

    return pkm_vector2f;
}

size2f_t csfml_size2f_to_pkm(sfVector2f csfml_vector2f)
{
    size2f_t pkm_size2f = {
        .width = csfml_vector2f.x,
        .height = csfml_vector2f.y
    };

    return pkm_size2f;
}
