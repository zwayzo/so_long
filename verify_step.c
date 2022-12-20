/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:35:09 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 03:41:07 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verify_right(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x][y + 1] != '1')
	{
		so_long->maps_tab[x][y] = '0';
		so_long->maps_tab[x][y + 1] = 'P';
		return (1);
	}
	return (0);
}

int	map_verify_left(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x][y - 1] != '1')
	{
		so_long->maps_tab[x][y] = '0';
		so_long->maps_tab[x][y - 1] = 'P';
		return (1);
	}
	return (0);
}

int	map_verify_up(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x - 1][y] != '1')
	{
		so_long->maps_tab[x][y] = '0';
		so_long->maps_tab[x - 1][y] = 'P';
		return (1);
	}
	return (0);
}

int	map_verify_down(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x + 1][y] != '1')
	{
		so_long->maps_tab[x][y] = '0';
		so_long->maps_tab[x + 1][y] = 'P';
		return (1);
	}
	return (0);
}
