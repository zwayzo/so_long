/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:01:53 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 07:01:20 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy(t_long *so_long, char **maps)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < so_long->longeur)
	{
		maps[i] = malloc(so_long->largeur * sizeof(char));
		maps[i][so_long->largeur - 1] = '\0';
		i++;
	}
	i = 0;
	while (i < so_long->longeur)
	{
		while (j < so_long->largeur)
		{
			maps[i][j] = so_long->maps_tab[i][j];
			j++;
		}
		i++;
		j = 0;
	}
}

void	init_struct(t_long *so_long)
{
	so_long->i = 0;
	so_long->x = 0;
	so_long->mlx = mlx_init();
}

void	to_loop(t_long *so_long)
{
	mlx_key_hook(so_long->mlx_win, evnts_handel, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, exit_function, so_long);
	mlx_loop(so_long->mlx);
	free (so_long);
}
