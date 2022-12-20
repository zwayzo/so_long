/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:44:45 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/20 17:38:25 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	left_verification(int pos_horizen, int pos_vertic, t_long *so_long)
{
	if (pos_horizen - 1 > 0 && so_long->maps_backup[pos_vertic]
		[pos_horizen - 1] != 'F' && so_long->maps_backup
		[pos_vertic][pos_horizen - 1] != 'E'
		&& so_long->maps_backup[pos_vertic][pos_horizen - 1] != '1'
		&& valide_path(so_long, pos_horizen - 1, pos_vertic) == 1)
		return (1);
	return (0);
}

int	down_verification(int pos_horizen, int pos_vertic, t_long *so_long)
{
	if (pos_vertic + 1 < so_long->longeur && so_long->maps_backup
		[pos_vertic + 1][pos_horizen] != 'F' && so_long->maps_backup
		[pos_vertic + 1][pos_horizen] != '1'
		&& so_long->maps_backup[pos_vertic + 1][pos_horizen]
		!= 'E' && valide_path(so_long, pos_horizen, pos_vertic + 1) == 1)
		return (1);
	return (0);
}

int	right_verification(int pos_horizen, int pos_vertic, t_long *so_long)
{
	if (pos_horizen + 1 < so_long->largeur && so_long->maps_backup
		[pos_vertic][pos_horizen + 1] != 'F' && so_long->maps_backup
		[pos_vertic][pos_horizen + 1] != '1' && so_long->maps_backup
		[pos_vertic][pos_horizen + 1] != 'E'
		&& valide_path(so_long, pos_horizen + 1, pos_vertic) == 1)
		return (1);
	return (0);
}

int	up_verification(int pos_horizen, int pos_vertic, t_long *so_long)
{
	if (pos_vertic > 0 && so_long->maps_backup[pos_vertic - 1]
		[pos_horizen] != 'F' && so_long->maps_backup
		[pos_vertic - 1][pos_horizen] != '1'
		&& so_long->maps_backup[pos_vertic - 1][pos_horizen]
		!= 'E' && valide_path(so_long, pos_horizen, pos_vertic - 1) == 1)
		return (1);
	return (0);
}

int	valide_path(t_long *so_long, int pos_horizen, int pos_vertic)
{
	int	i;
	int	j;

	i = toul_door(so_long);
	j = ord_door(so_long);
	if (so_long->maps_backup[pos_vertic][pos_horizen] != 1)
	{
		so_long->maps_backup[pos_vertic][pos_horizen] = 'F';
		if (left_verification(pos_horizen, pos_vertic, so_long) == 1)
			return (1);
		if (down_verification(pos_horizen, pos_vertic, so_long) == 1)
			return (1);
		if (right_verification(pos_horizen, pos_vertic, so_long) == 1)
			return (1);
		if (up_verification(pos_horizen, pos_vertic, so_long) == 1)
			return (1);
		so_long->maps_backup[pos_vertic][pos_horizen] = 'F';
	}
	if (coin_counter(so_long, so_long->maps_backup) == 0
		&& player_counter(so_long, so_long->maps_backup) == 0
		&& door_counter(so_long, so_long->maps_backup) == 1
		&& door_env(so_long, so_long->maps_backup) == 1)
		return (1);
	return (0);
}
