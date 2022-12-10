#include"so_long.h"
int ord_door()
{
    int fd = open("maps.ber",O_RDONLY);
    char *s;
    int i = 0;
    while (s || i == 0)
    {
        s = get_next_line(fd);
        while (s[i])
        {
            if (s[i] == 'E')
                return (i);
            i++;
        }
        i = 0;
    }
    return (0);
}

int toul_door()
{
    int fd = open("maps.ber",O_RDONLY);
    char *s;
    int i = 0;
    int j = 0;
    while (s || i == 0)
    {
        s = get_next_line(fd);
        while (s[i])
        {
            if (s[i] == 'E')
                return (j);
            i++;
        }
        i = 0;
        j++;
    }
    return (0);
}