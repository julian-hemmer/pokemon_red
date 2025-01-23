/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event
*/

#ifndef EVENT_H
    #define EVENT_H

    #include "pkm_scene.h"
    #include "pokemon.h"
    #include "sort_util.h"

typedef enum {
    MOUSE_PRESSED,
    MOUSE_RELEASED
} event_type_t;

typedef enum {
    HIGHEST = 0xFFFF,
    HIGH = 0x0FFF,
    NORMAL = 0x00FF,
    LOW = 0x000F,
    LOWEST = 0x0000
} event_priority_t;

typedef enum {
    LEFT,
    RIGHT,
    MIDDLE,
    XBUTTON1,
    XBUTTON2
} mouse_button_t;

typedef struct {
    mouse_button_t button;
    int x;
    int y;
} mouse_pressed_event_t;

typedef struct {
    event_type_t type;
    bool is_canceled;

    void *event_data;
} event_data_t;

typedef void (*event_handling_function_t)(
    game_info_t *game_info, event_data_t *event_data);

/**
 * Used only to create and event handler.
**/
typedef struct {
    event_priority_t priority;
    event_type_t target_event;
    scene_t target_scene;
    bool ignore_canceled;

    event_handling_function_t handling_function;
} event_handler_info_t;

typedef struct event_handler {
    event_priority_t priority;
    event_type_t target_event;
    scene_t target_scene;
    bool ignore_canceled;
    int call_count;

    event_handling_function_t handling_function;

    struct event_handler *next_handler;
} event_handler_t;

typedef struct {
    bool has_succed;
    event_handler_t *handler;
} event_handler_creation_t;

event_handler_creation_t register_handler(
    game_info_t *game_info,
    event_handler_info_t handler_info);

void destoy_handler(
    game_info_t *game_info,
    event_handler_t *handler);

void destoy_handlers(
    game_info_t *game_info);

void process_event(
    game_info_t *game_info,
    event_data_t *data);

void dump_event_handler(game_info_t *game_info);

int event_priority_ascending(void *o1, void *o2);
int event_priority_descending(void *o1, void *o2);

void sort_event(
    game_info_t *game_info,
    sort_function_t compare);

#endif /* !EVENT_H */
