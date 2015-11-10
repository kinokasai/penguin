#include "map.h"
#include "update.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: ./penguin map\n");
        exit(1);
    }
    struct map map = map_init(argv[1]);
    print_map(map);
    while (update(&map))
        print_map(map);
    printf("You won\n");
    return 0;
}
