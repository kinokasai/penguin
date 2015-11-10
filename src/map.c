#define _XOPEN_SOURCE 777

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

struct map map_init(char *name)
{
    FILE *file = fopen(name, "r");
    char *lineptr = NULL;
    struct map map;
    map.player = -1;
    map.finish = -1;
    size_t n = 0;
    getline(&lineptr, &n, file);
    lineptr[strlen(lineptr) - 1] = 0;
    map.w = atoi(lineptr);
    getline(&lineptr, &n, file);
    lineptr[strlen(lineptr) - 1] = 0;
    map.h = atoi(lineptr);
    getline(&lineptr, &n, file);
    map.data = lineptr;
    map.data[strlen(lineptr) - 1] = 0;
    for (int i = 0; i < strlen(map.data); i++)
    {
        if (map.data[i] == 'P')
            map.player = i;
        if (map.data[i] == 'F')
            map.finish = i;
    }
    if (map.player == -1 || map.finish == -1)
    {
        printf("Incorrect map\n");
        exit(1);
    }
    return map;
}

void print_map(struct map map)
{
    for (int i = 0; i < 100; i++)
        printf("\n");
    for (int i = 0; i < map.h; i++)
    {
        for (int j = 0; j < map.w; j++)
            printf("%c", map.data[i*map.w+j]);
        printf("\n");
    }
}
