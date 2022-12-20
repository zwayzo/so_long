/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:35:02 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/20 17:30:19 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	conditions(int fd, char *s, t_long *so_long)
{
	char	**maps;

	(void)fd;
	so_long->longeur = count_lines(s);
	so_long->maps_tab = map_stock(s, so_long);
	so_long->largeur = check_maps(so_long) - 1;
	if (s == NULL || so_long->largeur <= 0
		|| player_verification(s) != 1 || door_verification(s)
		!= 1 || check_letters(so_long) == 0)
	{
		ft_printf("ERROR!!!!\n");
		exit(1);
	}
	so_long->pos_horizen = player_position(so_long->maps_tab);
	so_long->pos_vertic = player_position2(so_long->maps_tab);
	maps = malloc(so_long->longeur * sizeof(char *));
	copy(so_long, maps);
	so_long->maps_backup = maps;
	if (valide_path(so_long, so_long->pos_horizen, so_long->pos_vertic) == 0)
	{
		ft_printf("THE PLAYER DOES NOT HAVE THE ACCES TO ALL THE COINS!!!");
		exit(1);
	}
}

void	windows_setup(char *map, t_long *so_long)
{
	int	fd;

	fd = open(map, O_RDONLY);
	so_long->mlx_win = mlx_new_window(so_long->mlx,
			so_long->largeur * 50, so_long->longeur * 50, "test");
	so_long->pos_horizen = player_position(so_long->maps_tab) * 50;
	so_long->pos_vertic = player_position2(so_long->maps_tab) * 50;
}

int	struct_fixe(t_long *so_long, int *i)
{
	so_long->move = 1;
	if (so_long->largeur == 0)
		return (0);
	*i = 0;
	so_long->j = 0;
	if (coin_counter(so_long, so_long->maps_tab) == 0)
	{
		ft_printf("INVALID NUMBER OF COIN\n");
		exit(1);
	}
	return (1);
}

void	image_setup(t_long *so_long)
{
	int	h;
	int	w;

	h = 80;
	w = 80;
	so_long->background = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/back.xpm", &h, &w);
	so_long->pac = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/pac.xpm", &h, &w);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/wall.xpm", &h, &w);
	so_long->coin = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/coin.xpm", &h, &w);
	so_long->door = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/door.xpm", &h, &w);
	so_long->pac_left = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/pac_left.xpm", &h, &w);
	so_long->pac_down = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/pac_down.xpm", &h, &w);
	so_long->pac_up = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/pac_up.xpm", &h, &w);
	so_long->door_open = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/door_open.xpm", &h, &w);
}

int	main(int ac, char **av)
{
	int		fd;
	t_long	*so_long;

	if (ac != 2 || extentions(av[1]) == 0)
		exit(1);
	so_long = malloc(sizeof(t_long));
	init_struct(so_long);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	conditions(fd, av[1], so_long);
	if (struct_fixe(so_long, &so_long->i) == 0)
		return (0);
	image_setup(so_long);
	if (so_long->largeur != 0)
	{
		close(fd);
		windows_setup(av[1], so_long);
		while (so_long->x < so_long->longeur)
			windows_paint(so_long->i, so_long, fd);
	}
	to_loop(so_long);
	return (0);
}
