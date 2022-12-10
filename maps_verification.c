#include "so_long.h"
int player_verification(t_long *so_long, char *maps)
{
    int i;
    int j;
    int fd;
    char *s;
    int p;

    i = 0;
    j = 0;
    p = 0;
    fd = open(maps,O_RDONLY);
    s = get_next_line(fd);
    while (s)
    {
        while (s[i])
        {
            if (s[i] == 'P')
                p++;
            i++;
        }
        i = 0;
        s = get_next_line(fd);
    }
    printf("p is %d\n",p);
    return (p);
}

int door_verification(t_long *so_long, char *maps)
{
    int i;
    int j;
    int fd;
    char *s;
    int p;

    i = 0;
    j = 0;
    p = 0;
    fd = open(maps,O_RDONLY);
    s = get_next_line(fd);
    while (s)
    {
        while (s[i])
        {
            if (s[i] == 'E')
                p++;
            i++;
        }
        i = 0;
        s = get_next_line(fd);
    }
    printf("p is %d\n",p);
    return (p);
}
