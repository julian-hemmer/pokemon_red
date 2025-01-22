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
    char *last_index = last_index_of(path, "/");
    size_t len;

    strncpy(dir, path, last_index == NULL ? sizeof(dir) : (dir - path));
    printf("dir path: %s\n", path);
    if (mkdir(dir, 0755) != 0 && errno != EEXIST)
        return -1;
    return 0;
}

int create_file_with_path(const char *path) {
    char *dir = strdup(path);
    char *filename = strrchr(dir, '/');

    if (dir == 0)
        return 0;
    if (filename != NULL) {
        *filename = '\0';
        filename++;
    } else {
        filename = dir;
    }
    if (create_dir(dir) == 0) {
        FILE *file = fopen(path, "a");
        if (file == NULL) {
            free(dir);
            return 0;
        }
        fclose(file);
    }
    free(dir);
    return 1;
}
