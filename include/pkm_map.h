/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pkm_map
*/

#ifndef PKM_MAP_H
    #define PKM_MAP_H

    #include "pkm_position.h"
    #include "pokemon.h"

typedef char byte_t;
typedef unsigned char ubyte_t;

// Lightweight struct for a big allocation.
typedef struct pokemon_tile {
    ubyte_t id;
    ubyte_t state;
    vector2s_t position;
} pokemon_tile_t;

// Circular linked list.
// Sprite position is the position inside the texture.
// The size if always the same see pokemon.h to see that.
typedef struct pokemon_tile_context {
    ubyte_t id;
    ubyte_t state;

    sfTexture *sprite_texture;
    vector2s_t sprite_position;
    
    pokemon_tile_context *next_context;
} pokemon_tile_context_t;

// The map is stored in 1d array.
typedef struct pokemon_map {
    char *file_path;
    ubyte_t id;
    pokemon_tile_t *map;

    ubyte_t current_map_id;
} pokemon_map_t;

pokemon_tile_t *get_tile_at(pokemon_map_t *map, vector2s_t position);

pokemon_map_t *load_map(char *map_filepath);
void destroy_map(pokemon_map_t *map);
void render_map(game_info_t *context, pokemon_map_t *map);

#endif /* !PKM_MAP_H */
