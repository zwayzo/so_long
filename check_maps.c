#include "so_long.h"
int check_maps(void)
{
    int i;
    int j;
    char *s;
    int len;

    i = 0;
    j = 0;
    int fd = open("maps.ber",O_RDONLY);
    j = count_lines();

    s = get_next_line(fd);
    len = ft_strlen(s);
    while (s[i])
    {
        if (s[i] == '0')
        {
            printf("MAPS INVALID (INCOMPLET WALL)\n");
            return (0);
        }
        i++;
    }
    i = 0;
    while (i < j - 2)
    {
        s = get_next_line(fd);
        // printf("%d---%d---%s\n",ft_strlen(s),len,s);
        if (s[0] != '1' || s[ft_strlen(s) - 2] != '1')
        {
            printf("MAPS INVALID (LES COTES)\n");
            return (0);
        }
        else if (ft_strlen(s)!= len)
        {
            // printf("---\n");
            printf("INVALID LENGHT\n");
            return (0);
        }
        i++;
    }
    s = get_next_line(fd);
    if (ft_strlen(s) + 1!= len)
    {
        // printf("---\n");
        printf("INVALID LENGHT\n");
        return (0);
    }
    i = 0;
    while (s[i])
    {
        if (s[i] == '0')
        {
            printf("MAPS INVALID (INCOMPLET WALL)\n");
            return (0);
        }
        i++;
    }
    printf("MAPS VALID :)\n");
    return (i);
}
