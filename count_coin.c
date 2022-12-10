#include"so_long.h"
int salam(t_long *so_long, char **s)
{
    int i;
    int j;
    int x;

    i = 0;
    j = 0;
    x = 0;
    while (i <  so_long->longeur)
    {
        while (j < so_long->largeur)
        {
            if (s[i][j] == 'C')
                x++;
            j++;
        }
        j = 0;
        i++;
    }
    return (x);
}