#include "so_long.h"
int count_lines()
{
    int fd;
    char *s;
    int i;

    i = 0;
    fd = open("maps.ber",O_RDONLY);
    while (i == 0 || s != NULL)
    {
        i++;
        s = get_next_line(fd);
    }
    return (i - 1);
}
