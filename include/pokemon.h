/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** pokemon
*/

#ifndef POKEMON
    #define POKEMON

typedef struct game_info {
    char *window_name;
} game_info_t;

int load_game(game_info_t *game_info);

#endif /* !POKEMON */
