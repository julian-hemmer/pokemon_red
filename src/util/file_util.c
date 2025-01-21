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

int create_dir(const char *path)
{
    char temp[256];
    char *dir = NULL;
    size_t len;

    strncpy(temp, path, sizeof(temp));
    if (temp[strlen(temp) - 1] == '/')
        temp[strlen(temp) - 1] = '\0';
    len = strlen(temp);
    for (size_t i = 1; i < len; i++) {
        if (temp[i] != '/')
            continue;
        temp[i] = '\0';
        dir = temp;
        if (mkdir(dir, 0755) != 0 && errno != EEXIST)
            return -1;
        temp[i] = '/';
    }
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
