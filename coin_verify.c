#include "so_long.h"
int coin_verify_right(int i, int j, t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x][y + 1] == 'C')
    {
        so_long->maps_tab[x][y + 1] = '0';
        return (1);
    }
    return (0);
}

#include "so_long.h"
int coin_verify_left(int i, int j, t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x][y - 1] == 'C')
    {
        so_long->maps_tab[x][y - 1] = '0';
        return (1);
    }
    return (0);
}

#include "so_long.h"
int coin_verify_up(int i, int j, t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x - 1][y] == 'C')
    {
        so_long->maps_tab[x - 1][y] = '0';
        return (1);
    }
    return (0);
}

#include "so_long.h"
int coin_verify_down(int i, int j, t_long *so_long)
{
    int x = i /= 50;
    int y =  j /= 50;
    if (so_long->maps_tab[x + 1][y] == 'C')
    {
        so_long->maps_tab[x + 1][y] = '0';
        return (1);
    }
    return (0);
}