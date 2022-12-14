/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:30:05 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 05:45:34 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *map)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	fd = open(map, O_RDONLY);
	while (i == 0 || ft_strlen(s) != 0)
	{
		if (ft_strlen(s) != 0)
			free (s);
		i++;
		s = get_next_line(fd);
	}
	free (s);
	return (i - 1);
}
