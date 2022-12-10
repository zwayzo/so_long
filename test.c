
#include "so_long.h"

int	main(int ac, char **av)
{
	int h = 20;
	int w = 80;
	t_long *so_long;
	so_long = malloc(sizeof(t_long));
	so_long->mlx = mlx_init();
	so_long->background = mlx_xpm_file_to_image(so_long->mlx,"pictures/back.xpm",&h,&w);
	so_long->img2 = mlx_xpm_file_to_image(so_long->mlx,"pictures/pac.xpm",&h,&w);
	so_long->img3 = mlx_xpm_file_to_image(so_long->mlx,"pictures/wall.xpm",&h,&w);
	so_long->img5 = mlx_xpm_file_to_image(so_long->mlx,"pictures/coin.xpm",&h,&w);
	so_long->img6 = mlx_xpm_file_to_image(so_long->mlx,"pictures/door.xpm",&h,&w);
	so_long->pac_left = mlx_xpm_file_to_image(so_long->mlx,"pictures/pac_left.xpm",&h,&w);
	so_long->pac_down = mlx_xpm_file_to_image(so_long->mlx,"pictures/pac_down.xpm",&h,&w);
	so_long->pac_up = mlx_xpm_file_to_image(so_long->mlx,"pictures/pac_up.xpm",&h,&w);
	so_long->door_open = mlx_xpm_file_to_image(so_long->mlx,"pictures/door_open.xpm",&h,&w);


    int i = 0;
	int x = 0;
	int count_coin;
	char *s;
	int fd = open(av[1],O_RDONLY);
	if (get_next_line(fd) == NULL)
	{
		printf("ther is no map!!!!\n");
		exit(1);
	}
	if (player_verification(so_long, av[1]) != 1)
	{
		printf("INVALID NUMBER OF PLAYER\n");
		exit(1);
	}
	if (door_verification(so_long, av[1]) != 1)
	{
		printf("INVALID NUMBER OF DOOR\n");
		exit(1);
	}
	so_long->longeur = count_lines();
	so_long->largeur = check_maps();
	if (so_long->largeur == 0)
		return (0);
	i = 0;
	so_long->j = 0;
	so_long->maps_tab = map_stock();
	so_long->door_horiz=toul_door();
	so_long->door_verti=ord_door();
    if (so_long->largeur != 0)
    {
		fd = open(av[1],O_RDONLY);
		so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->largeur * 50, so_long->longeur * 50, "test");
		so_long->pos_horizen = player_position() * 50;
		so_long->pos_vertic = player_position2() * 50;
		while (x <so_long->longeur)
		{
			so_long->coin_number = salam(so_long,so_long->maps_tab);
        	s = get_next_line(fd);
        	while (s[i])
        	{
        	    if (s[i] == '1')
        	        mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->img3, so_long->j, so_long->n);
        	    else if (s[i] == 'C')
				{
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->j, so_long->n);
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->img5, so_long->j, so_long->n);
				}
				else if (s[i] == 'P')
				{
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->j, so_long->n);
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->img2, so_long->j, so_long->n);
				
				}
				else if (s[i] == 'E' && so_long->coin_number != 0)
				{
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->j, so_long->n);
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->img6, so_long->j, so_long->n);
				
				}
				else if (s[i] == 'E' && so_long->coin_number == 0)
				{
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->j, so_long->n);
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->door_open, so_long->j, so_long->n);
				
				}
				else if (s[i]== '0')
					mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->background, so_long->j, so_long->n);
				i = i + 1;
        	    so_long->j = so_long->j + 50;
        	}
			x++;
			so_long->j = 0;
			so_long->n = so_long->n + 50;
			i = 0;
			printf("{%d}--{%d}\n",x, so_long->longeur);

			printf("seee\n");
		}
    }
	mlx_key_hook(so_long->mlx_win, evnts_handel, so_long);
    mlx_loop(so_long->mlx);
	return (0);
}
