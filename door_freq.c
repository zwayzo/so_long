/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_freq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:30:13 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 01:06:41 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ord_door(t_long *so_long)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (so_long->maps_tab[i] || i == 0)
	{
		while (so_long->maps_tab[i][j])
		{
			if (so_long->maps_tab[i][j] == 'E')
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	toul_door(t_long *so_long)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (so_long->maps_tab[i] || i == 0)
	{
		while (so_long->maps_tab[i][j])
		{
			if (so_long->maps_tab[i][j] == 'E')
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
