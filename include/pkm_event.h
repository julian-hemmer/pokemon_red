/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event
*/

#ifndef PKM_EVENT_H
    #define PKM_EVENT_H

    #include "pkm_scene.h"
    #include "pokemon.h"
    #include "sort_util.h"

/*+----------+----------+*/
/*+    EVENT RESOLVER   +*/
/*+----------+----------+*/

typedef void (*csfml_resolver_function_t)(game_context_t *game_context,
    sfEvent event);

typedef struct csfml_event_resolver {
    sfEventType type;
    csfml_resolver_function_t function;
} csfml_event_resolver_t;

extern const csfml_event_resolver_t CSFML_EVENT_RESOLVER[];
extern const size_t CSFML_EVENT_RESOLVER_COUNT;

void csfml_event_mouse_pressed(game_context_t *game_context, sfEvent event);
void csfml_event_mouse_released(game_context_t *game_context, sfEvent event);
void csfml_window_closed_event(game_context_t *game_context, sfEvent event);

/*+----------+----------+*/
/*+        EVENT        +*/
/*+----------+----------+*/

typedef enum {
    PRE_UPDATE,
    POST_UPDATE,
    MOUSE_PRESSED,
    MOUSE_RELEASED,
    WINDOW_CLOSED
} event_type_t;

/*+----------+----------+*/
/*+        MOUSE        +*/
/*+----------+----------+*/

typedef enum {
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_MIDDLE,
    BUTTON_XBUTTON1,
    BUTTON_XBUTTON2
} mouse_button_t;

typedef struct csfml_button_resolver {
    sfMouseButton csfmlButton;
    mouse_button_t pkmButton;
} csfml_button_resolver_t;

extern const csfml_button_resolver_t CSFML_BUTTON_RESOLVER[];

mouse_button_t csfml_button_resolver(sfMouseButton button);
sfMouseButton pkm_button_resolver(mouse_button_t button);

/*+        PRESSED        +*/

typedef struct {
    mouse_button_t button;
    int x;
    int y;
} mouse_pressed_event_t;

/*+      RELEASED        +*/

typedef struct {
    mouse_button_t button;
    int x;
    int y;
} mouse_released_event_t;

/*+----------+----------+*/
/*+        -----        +*/
/*+----------+----------+*/

typedef enum {
    HIGHEST = 0xFFFF,
    HIGH = 0x0FFF,
    NORMAL = 0x00FF,
    LOW = 0x000F,
    LOWEST = 0x0000
} event_priority_t;

typedef struct {
    event_type_t type;
    bool is_canceled;

    void *event_data;
} event_data_t;

typedef void (*event_handling_function_t)(
    game_context_t *game_context, event_data_t *event_data);

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
    game_context_t *game_context,
    event_handler_info_t handler_info);

void destoy_handler(
    game_context_t *game_context,
    event_handler_t *handler);

void destoy_handlers(
    game_context_t *game_context);

void process_event(
    game_context_t *game_context,
    event_data_t *data);

void process_csfml_event(
    game_context_t *game_context,
    sfEvent event);

void dump_event_handler(game_context_t *game_context);

int event_priority_ascending(void *o1, void *o2);
int event_priority_descending(void *o1, void *o2);

void sort_event(
    game_context_t *game_context,
    sort_function_t compare);

void window_close_handler(game_context_t *game_context, event_data_t *);

#endif /* !PKM_EVENT_H */
