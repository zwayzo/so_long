/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:33:56 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/18 21:18:27 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_stock(char *map, t_long *so_long)
{
	char	**str;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	str = malloc((so_long->longeur + 1) * sizeof(char *));
	while (i < so_long->longeur)
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	return (str);
}
