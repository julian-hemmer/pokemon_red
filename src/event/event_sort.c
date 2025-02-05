/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_sort
*/

#include "pkm_event.h"

static event_handler_t *merge(event_handler_t *left,
    event_handler_t *right, sort_function_t compare)
{
    if (!left)
        return right;
    if (!right)
        return left;
    if (compare(left, right) <= 0) {
        left->next_handler = merge(left->next_handler, right, compare);
        return left;
    } else {
        right->next_handler = merge(left, right->next_handler, compare);
        return right;
    }
}

static void split_list(event_handler_t *source,
    event_handler_t **front, event_handler_t **back)
{
    event_handler_t *slow = source;
    event_handler_t *fast = source->next_handler;

    while (fast) {
        fast = fast->next_handler;
        if (fast) {
            slow = slow->next_handler;
            fast = fast->next_handler;
        }
    }
    (*front) = source;
    (*back) = slow->next_handler;
    slow->next_handler = NULL;
}

static void merge_sort(
    event_handler_t **handlers,
    sort_function_t compare)
{
    event_handler_t *front = NULL;
    event_handler_t *back = NULL;

    if (!handlers || !(*handlers) ||
        !((*handlers)->next_handler)) {
        return;
    }
    split_list((*handlers), &front, &back);
    merge_sort(&front, compare);
    merge_sort(&back, compare);
    (*handlers) = merge(front, back, compare);
}

int event_priority_ascending(void *o1, void *o2)
{
    event_handler_t *h1 = ((event_handler_t *) o1);
    event_handler_t *h2 = ((event_handler_t *) o2);

    return h1->priority - h2->priority;
}

int event_priority_descending(void *o1, void *o2)
{
    event_handler_t *h1 = ((event_handler_t *) o1);
    event_handler_t *h2 = ((event_handler_t *) o2);

    return h2->priority - h1->priority;
}

void sort_event(
    game_context_t *game_context,
    sort_function_t compare)
{
    merge_sort(&(game_context->handlers), compare);
}
