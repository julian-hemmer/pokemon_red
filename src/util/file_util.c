/*
** EPITECH PROJECT, 2025
** pokemon_red
** File description:
** file_util
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "file_util.h"
#include "string_util.h"

int create_dir(const char *path)
{
    char dir[256];
    int last_index = last_index_of(path, '/');

    strncpy(dir, path, last_index == -1 ? sizeof(dir) : (size_t)last_index);
    dir[last_index] = 0;
    if (mkdir(dir, 0755) != 0 && errno != EEXIST)
        return -1;
    return 0;
}

int create_file_with_path(const char *path)
{
    FILE *file = NULL;

    if (create_dir(path) == 0) {
        file = fopen(path, "a");
        if (file == NULL)
            return 0;
        fclose(file);
    }
    return 1;
}
