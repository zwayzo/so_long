/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:34:51 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 07:21:27 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	player_position(char **maps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (maps[i] || i == 0)
	{
		while (maps[i][j])
		{
			if (maps[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
