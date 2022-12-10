#include"so_long.h"


int evnts_handel(int key, t_long *so_long)
{
    int h = 20;
	int w = 80;
    int p = 0;
    char **x = so_long->maps_tab;
    int count_coin;

    count_coin = salam(so_long, x);
    p = 0;
    if (count_coin == 0)
    {
        so_long->door_open = mlx_xpm_file_to_image(so_long->mlx,"pictures/door_open.xpm",&h,&w);
        mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->door_open  ,so_long->door_verti * 50, so_long->door_horiz * 50);

    }
    if (key == 124) //right
    {
        if (coin_verify_right(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1)
            mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen+50, so_long->pos_vertic);
        if (map_verify_right(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1 )
        {
            if ((so_long->pos_horizen / 50 + 1 != so_long->door_verti || so_long->pos_vertic / 50 != so_long->door_horiz) || count_coin == 0)
            {
                so_long->maps_tab[so_long->pos_vertic / 50][(so_long->pos_horizen / 50) + 1] = 'P';
                so_long->maps_tab[so_long->pos_vertic / 50][(so_long->pos_horizen / 50)] = '0';
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen, so_long->pos_vertic);
                so_long->pos_horizen+= 50;
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->img2, so_long->pos_horizen, so_long->pos_vertic);
            }
        }
    }
    else if (key == 123) //left
    {
        if (coin_verify_left(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1)
            mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen-50, so_long->pos_vertic);
       if (map_verify_left(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1)
       {
            if ((so_long->pos_horizen / 50 - 1 != so_long->door_verti || so_long->pos_vertic / 50 != so_long->door_horiz) || count_coin == 0)
            {
                so_long->maps_tab[so_long->pos_vertic / 50][(so_long->pos_horizen / 50) - 1] = 'P';
                so_long->maps_tab[so_long->pos_vertic / 50][(so_long->pos_horizen / 50)] = '0';
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen, so_long->pos_vertic);
                so_long->pos_horizen -= 50;
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->pac_left, so_long->pos_horizen, so_long->pos_vertic);
            }
       }
    }
    else if (key == 126) //up
    {
        if (coin_verify_up(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1)
            mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen, so_long->pos_vertic - 50);
        if (map_verify_up(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1)
        {

            if ((so_long->pos_horizen / 50 != so_long->door_verti || so_long->pos_vertic / 50 - 1 != so_long->door_horiz) || count_coin == 0)
            {
                so_long->maps_tab[(so_long->pos_vertic / 50) - 1][so_long->pos_horizen / 50] = 'P';
                so_long->maps_tab[so_long->pos_vertic / 50][so_long->pos_horizen / 50] = '0';
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen, so_long->pos_vertic);
                so_long->pos_vertic -= 50;
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->pac_up, so_long->pos_horizen, so_long->pos_vertic);
            }
        }
    }
    else if (key == 125) //down
    {
        if (coin_verify_down(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1)
            mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen, so_long->pos_vertic + 50);
        if (map_verify_down(so_long->pos_vertic, so_long->pos_horizen, so_long) == 1)
        {
            if ((so_long->pos_horizen / 50 != so_long->door_verti || so_long->pos_vertic / 50 + 1 != so_long->door_horiz) || count_coin == 0)
            {
                so_long->maps_tab[(so_long->pos_vertic / 50) + 1][so_long->pos_horizen / 50] = 'P';
                so_long->maps_tab[so_long->pos_vertic / 50][so_long->pos_horizen / 50] = '0';
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->pos_horizen, so_long->pos_vertic);
                so_long->pos_vertic += 50;
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->pac_down, so_long->pos_horizen, so_long->pos_vertic);
            }
        }
    }
    if (so_long->pos_vertic == so_long->door_horiz * 50 && so_long->pos_horizen == so_long->door_verti * 50)
        exit(0);
    
    return (0);
}