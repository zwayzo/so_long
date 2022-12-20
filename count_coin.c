/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:29:52 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/20 17:38:19 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	coin_counter(t_long *so_long, char **maps)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (i < so_long->longeur)
	{
		while (j < so_long->largeur)
		{
			if (maps[i][j] == 'C')
				x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (x);
}

int	door_counter(t_long *so_long, char **maps)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (i < so_long->longeur)
	{
		while (j < so_long->largeur)
		{
			if (maps[i][j] == 'E')
				x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (x);
}

int	player_counter(t_long *so_long, char **maps)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (i < so_long->longeur)
	{
		while (j < so_long->largeur)
		{
			if (maps[i][j] == 'P')
				x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (x);
}

int	door_env(t_long *so_long, char **maps)
{
	so_long->door_horiz = toul_door(so_long);
	so_long->door_verti = ord_door(so_long);
	if (maps[so_long->door_horiz + 1][so_long->door_verti] == 'F'
		|| maps[so_long->door_horiz - 1][so_long->door_verti] == 'F'
		|| maps[so_long->door_horiz][so_long->door_verti + 1] == 'F'
		|| maps[so_long->door_horiz][so_long->door_verti - 1] == 'F')
		return (1);
	return (0);
}
