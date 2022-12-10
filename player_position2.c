#include"so_long.h"
int player_position2()
{
    int fd = open("maps.ber",O_RDONLY);
    char *s;
    int i = 0;
    int x = 0;

    while(s || i == 0)
    {
        s = get_next_line(fd);
        while (s[i])
        {
            if (s[i] == 'P')
            {
                return(x);
            }
            i++;
        }
        x++;
        i = 0;
    }
    return (0); 
}