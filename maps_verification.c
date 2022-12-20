/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:34:02 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 03:57:08 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_verification(char *maps)
{
	int		i;
	int		j;
	int		fd;
	char	*s;
	int		p;

	i = 0;
	j = 0;
	p = 0;
	fd = open(maps, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		while (s[i])
		{
			if (s[i] == 'P')
				p++;
			i++;
		}
		i = 0;
		free (s);
		s = get_next_line(fd);
	}
	free (s);
	return (p);
}

int	door_verification(char *maps)
{
	int		i;
	int		j;
	int		fd;
	char	*s;
	int		p;

	i = 0;
	j = 0;
	p = 0;
	fd = open(maps, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		while (s[i])
		{
			if (s[i] == 'E')
				p++;
			i++;
		}
		i = 0;
		free (s);
		s = get_next_line(fd);
	}
	return (p);
}
