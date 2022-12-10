#include "so_long.h"

int map_verify_right(int i, int j,t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x][y + 1] != '1')
    {
        so_long->maps_tab[x][y] = '0';
        so_long->maps_tab[x][y + 1] = 'P';
        return (1);
    }
    return (0);
}

int map_verify_left(int i, int j,t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x][y - 1] != '1')
    {
        so_long->maps_tab[x][y] = '0';
        so_long->maps_tab[x][y - 1] = 'P';
        return (1);
    }
    return (0);
}

int map_verify_up(int i, int j,t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x - 1][y] != '1')
    {
        so_long->maps_tab[x][y] = '0';
        so_long->maps_tab[x - 1][y] = 'P';
        return (1);
    }
    return (0);
}

int map_verify_down(int i, int j,t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x + 1][y] != '1')
    {
        so_long->maps_tab[x][y] = '0';
        so_long->maps_tab[x + 1][y] = 'P';
        return (1);
    }
    return (0);
}