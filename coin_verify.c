/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_verify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:29:34 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/17 22:41:34 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin_verify_right(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x][y + 1] == 'C')
	{
		so_long->maps_tab[x][y + 1] = '0';
		return (1);
	}
	return (0);
}

int	coin_verify_left(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x][y - 1] == 'C')
	{
		so_long->maps_tab[x][y - 1] = '0';
		return (1);
	}
	return (0);
}

int	coin_verify_up(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x - 1][y] == 'C')
	{
		so_long->maps_tab[x - 1][y] = '0';
		return (1);
	}
	return (0);
}

int	coin_verify_down(int i, int j, t_long *so_long)
{
	int	x;
	int	y;

	x = i / 50;
	y = j / 50;
	if (so_long->maps_tab[x + 1][y] == 'C')
	{
		so_long->maps_tab[x + 1][y] = '0';
		return (1);
	}
	return (0);
}
