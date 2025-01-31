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

// Tile_id -> And identifier to know what kind of tile its is (Use for rendering and processeing)
typedef struct pokemon_tile {
    byte_t id;
    byte_t state;
    vector2f_t position;
} pokemon_tile_t;

// The map is stored in 1d array. 
typedef struct pokemon_map {
    byte_t id;
    pokemon_tile_t **map;
} pokemon_map_t;

typedef struct pokemon_map_context {
    char *file_path;
    pokemon_map_t **maps;

    byte_t current_map_id;
} pokemon_map_context_t;

pokemon_tile_t *get_tile_at(pokemon_map_t *map, vector2f_t position);

pokemon_map_context_t *load_map_context(char *map_filepath);
void destroy_map(pokemon_map_t *map);
void render_map(game_info_t *context, pokemon_map_t *map);

#endif /* !PKM_MAP_H */
