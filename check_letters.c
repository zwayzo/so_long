/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:30:25 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 02:45:38 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_letters(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < so_long->longeur)
	{
		while (j < so_long->largeur)
		{
			if (so_long->maps_tab[i][j] != 'E' && so_long->maps_tab[i][j]
				!= 'P' && so_long->maps_tab[i][j] != '1'
				&& so_long->maps_tab[i][j] != '0'
				&& so_long->maps_tab[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	exit_function(void *out)
{
	(void ) out;
	exit(0);
}
