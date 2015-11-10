#include "update.h"

#include <stdio.h>

int update(struct map *map)
{
    int input = getchar();
    map->data[map->player] = '3';
    int new_pos = map->player;
    if (input == 'z')
        new_pos = map->player - map->w;
    else if (input == 'q')
        new_pos = map->player - 1;
    else if (input == 's')
        new_pos = map->player + map->w;
    else if (input == 'd')
        new_pos = map->player + 1;
    if (new_pos == map->finish)
        return 0;
    else if (map->data[new_pos] == 'K')
        map->haskey = 1;
    if ((map->data[new_pos] == '1' || map->data[new_pos] == 'F' ||
                map->data[new_pos] == 'K' ||
                (map->data[new_pos] == 'G' && map->haskey)) &&
            (new_pos > 0 && new_pos < map->w * map->h))
        map->player = new_pos;
    map->data[map->player] = 'P';
    while (getchar() != '\n');
    return 1;
}
