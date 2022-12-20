/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:30:24 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 02:38:49 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	no_coin(t_long *so_long)
{
	int		h;
	int		w;

	h = 20;
	w = 20;
	so_long->door_open = mlx_xpm_file_to_image(so_long->mlx,
			"pictures/door_open.xpm", &h, &w);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->door_open, so_long->door_verti * 50,
		so_long->door_horiz * 50);
}

int	evnts_handel(int key, t_long *so_long)
{
	so_long->count_coin = coin_counter(so_long, so_long->maps_tab);
	if (so_long->count_coin == 0)
		no_coin(so_long);
	if (key == 53)
		exit(1);
	else if (key == 124 || key == 2)
		move_right(so_long);
	else if (key == 123 || key == 0)
		move_left(so_long);
	else if (key == 126 || key == 13)
		move_up(so_long);
	else if (key == 125 || key == 1)
		move_down(so_long);
	if (so_long->pos_vertic == so_long->door_horiz * 50
		&&so_long->pos_horizen == so_long->door_verti * 50)
		exit(0);
	return (0);
}
