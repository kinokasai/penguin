#include "update.h"

#include <stdio.h>
#include <stdarg.h>

static char walkable_var(int pos, int count, ...)
{
    char walkable = 0;
    va_list args;
    va_start(args, count);
    while (count--)
        walkable = walkable || (pos == va_arg(args, int));
    return walkable;
}

static char can_walk(struct map *map, int pos)
{
    char cpos = map->data[pos];
    char walkable = walkable_var(cpos, 3, '1', 'F', 'K');
    walkable = walkable || (cpos == 'G' && map->haskey);
    walkable = walkable && (pos > 0 && pos < map->w * map->h);
    return walkable;
}

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
    if (can_walk(map, new_pos))
        map->player = new_pos;
    map->data[map->player] = 'P';
    while (getchar() != '\n');
    return 1;
}
