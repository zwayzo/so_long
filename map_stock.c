#include "so_long.h"
char **map_stock()
{
    char *s;
    char **str;
    int i = 0;
    int j = 0;
    int fd;
    fd = open("maps.ber",O_RDONLY);
    str = malloc((count_lines() + 1) * sizeof(char *));
    while (i < count_lines())
    {
        str[i] = get_next_line(fd);
        i++;
    }
    return (str);
}