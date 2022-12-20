/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:29:43 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 05:47:51 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_last_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i + 1])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	loop(t_long *so_long, int len, int i)
{
	while (i < so_long->longeur - 1)
	{
		if (so_long->maps_tab[i][0] != '1' || so_long->maps_tab[i]
			[ft_strlen(so_long->maps_tab[i]) - 2] != '1'
			|| ft_strlen(so_long->maps_tab[i]) != len)
			return (0);
		i++;
	}
	return (i);
}

int	check_maps(t_long *so_long)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(so_long->maps_tab[0]);
	if (len == 0 || check_wall(so_long->maps_tab[i]) == 0)
		return (0);
	i++;
	if (loop(so_long, len, i) == 0)
		return (0);
	if (ft_strlen(so_long->maps_tab[so_long->longeur - 1])
		+ 1 != len || check_last_wall(so_long->maps_tab
			[so_long->longeur - 1]) == 0)
		return (0);
	return (len);
}
