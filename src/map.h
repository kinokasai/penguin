#ifndef MAP_H
# define MAP_H

struct map
{
    int w;
    int h;
    int player;
    int finish;
    char *data;
};

struct player
{
    int x;
    int y;
};

struct map map_init(char *name);
void print_map(struct map map);

#endif /* MAP_H */
