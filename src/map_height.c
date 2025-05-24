#include "so_long.h"

void map_height(t_root *root, char *file)
{
    int i;
    int j;

    root->game->height = 1;
    i = root->game->width + 1;
    while (file[i] != 0)
    {
        j = 0;
        while (file[i + j] != 0 && file[i + j] != '\n')
            j++;
        if (root->game->width != j)
        {
            free(file);
            root_destroy(root, "map format is invalid", 0);
        }
        i += root->game->width + 1;
        root->game->height++;
    }
}