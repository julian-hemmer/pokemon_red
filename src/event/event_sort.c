/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** event_sort
*/

#include "pkm_event.h"
#include "sort_util.h"

static event_handler_t *get_last_elem(event_handler_t **list_ptr)
{
    event_handler_t *cpy = *list_ptr;

    if (cpy == NULL)
        return NULL;
    while (cpy->next_handler != NULL) {
        cpy = cpy->next_handler;
    }
    return cpy;
}

static void process_half(event_handler_t **half,
    event_handler_t **new_node)
{
    event_handler_t *temp = 0;

    if ((*half) == NULL)
        return;
    if ((*new_node) == NULL) {
        (*new_node) = (*half);
        (*half) = (*half)->next_handler;
        (*new_node)->next_handler = NULL;
    } else {
        temp = (*half);
        get_last_elem(new_node)->next_handler = temp;
        (*half) = (*half)->next_handler;
        temp->next_handler = NULL;
        get_last_elem(new_node)->next_handler = NULL;
    }
}

static int half_checker(event_handler_t **first_half,
    event_handler_t **second_half,
    event_handler_t **new_node, sort_function_t *compare)
{
    if ((*first_half) == NULL || ((*second_half) != NULL && (*compare)(
            (*first_half), (*second_half)) > 0)) {
        process_half(second_half, new_node);
        return 1;
    }
    return 0;
}

static event_handler_t *merge_back_list(
    event_handler_t *first_half, event_handler_t *second_half,
    int (*cmp[])(void *, void *))
{
    event_handler_t *new_node = 0;
    sort_function_t *compare = cmp;

    while (first_half != NULL || second_half != NULL) {
        if (half_checker(&first_half, &second_half, &new_node, compare) ||
            half_checker(&second_half, &first_half, &new_node, compare)) {
            compare = cmp;
            continue;
        }
        compare++;
        if ((*compare) != 0)
            continue;
        process_half(&first_half, &new_node);
        process_half(&second_half, &new_node);
        compare = cmp;
    }
    return new_node;
}

void ll_sort(event_handler_t **pivot,
    int (*cmp[])(void *, void *))
{
    event_handler_t *first_half = 0;
    event_handler_t *second_half = 0;
    event_handler_t *checker = 0;

    if (pivot == 0 || *pivot == 0 || (*pivot)->next_handler == 0)
        return;
    first_half = *pivot;
    checker = *pivot;
    for (int i = 1; checker->next_handler != NULL; i++) {
        if (i % 2 == 0)
            first_half = first_half->next_handler;
        checker = checker->next_handler;
    }
    second_half = first_half->next_handler;
    first_half->next_handler = NULL;
    first_half = *pivot;
    ll_sort(&second_half, cmp);
    ll_sort(&first_half, cmp);
    (*pivot) = merge_back_list(first_half, second_half, cmp);
}
