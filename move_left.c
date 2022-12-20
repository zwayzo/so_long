/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:34:32 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/17 23:52:31 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_up_left(t_long *so_long)
{
	so_long->maps_tab[so_long->pos_vertic / 50]
	[(so_long->pos_horizen / 50) - 1] = 'P';
	so_long->maps_tab[so_long->pos_vertic / 50]
	[(so_long->pos_horizen / 50)] = '0';
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->background, so_long->pos_horizen,
		so_long->pos_vertic);
	so_long->pos_horizen -= 50;
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->pac_left, so_long->pos_horizen,
		so_long->pos_vertic);
	ft_printf("move : %d\n", so_long->move);
	so_long->move++;
}

void	move_left(t_long *so_long)
{
	char	**x;

	x = so_long->maps_tab;
	if (coin_verify_left(so_long->pos_vertic,
			so_long->pos_horizen, so_long) == 1)
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->background, so_long->pos_horizen - 50,
			so_long->pos_vertic);
	if (map_verify_left(so_long->pos_vertic,
			so_long->pos_horizen, so_long) == 1)
	{
		if ((so_long->pos_horizen / 50 - 1 != so_long->door_verti
				|| so_long->pos_vertic / 50 != so_long->door_horiz)
			|| so_long->count_coin == 0)
			set_up_left(so_long);
	}
}
