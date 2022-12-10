#include"so_long.h"
int player_position()
{
    int fd = open("maps.ber",O_RDONLY);
    char *s;
    int i = 0;

    while(s || i == 0)
    {
        s = get_next_line(fd);
        while (s[i])
        {
            if (s[i] == 'P')
            {
                return(i);
            }
            i++;
        }
        i = 0;
    }
    return (0); 
}