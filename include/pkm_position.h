/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pkm_position
*/

#ifndef PKM_POSITION_H
    #define PKM_POSITION_H

    #include "pkm_int.h"

/*+      2D DECIMAL        +*/

typedef struct vector2f {
    double x;
    double y;
} vector2f_t;

typedef struct size2f {
    double width;
    double height;
} size2f_t;

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

#endif /* !PKM_POSITION_H */
