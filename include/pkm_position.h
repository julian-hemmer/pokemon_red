/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pkm_position
*/

#ifndef PKM_POSITION_H
    #define PKM_POSITION_H

    #include <stdint.h>
    #include <SFML/Graphics.h>

/*+      2D DECIMAL        +*/

typedef struct vector2f {
    double x;
    double y;
} vector2f_t;

typedef struct size2f {
    double width;
    double height;
} size2f_t;

/*+      CONVERTOR        +*/

sfVector2f pkm_vector2f_to_csfml(vector2f_t pkm_vector2f);
sfVector2f pkm_size2f_to_csfml(size2f_t pkm_size2f);
vector2f_t csfml_vector2f_to_pkm(sfVector2f csfml_vector2f);
size2f_t csfml_size2f_to_pkm(sfVector2f csfml_vector2f);

/*+      CONSTRUCTOR        +*/

vector2f_t pkm_vector2f(double x, double y);
size2f_t pkm_size2f(double width, double height);

/*+      2D UNSIGNED        +*/

typedef struct vector2u {
    uint64_t x;
    uint64_t y;
} vector2u_t;

typedef struct size2u {
    uint64_t width;
    uint64_t height;
} size2u_t;

/*+      2D INTEGER        +*/

typedef struct vector2i {
    int64_t x;
    int64_t y;
} vector2i_t;

typedef struct size2i {
    int64_t width;
    int64_t height;
} size2i_t;

/*+      2D short        +*/

typedef struct vector2s {
    int16_t x;
    int16_t y;
} vector2s_t;

typedef struct size2s {
    int16_t width;
    int16_t height;
} size2s_t;

#endif /* !PKM_POSITION_H */
