/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:34:47 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 01:14:50 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	player_position2(char **maps)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	j = 0;
	while (maps[i] || i == 0)
	{
		while (maps[i][j])
		{
			if (maps[i][j] == 'P')
				return (x);
			j++;
		}
		x++;
		i++;
		j = 0;
	}
	return (0);
}
