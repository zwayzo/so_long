/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extentions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 05:23:39 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 05:52:22 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extentions(char *map)
{
	int	len;
	int	j;

	len = ft_strlen(map);
	j = len - 3;
	while (len != j)
	{
		if (map[len-- - 1] == 'r')
		{
			if (map[len-- - 1] == 'e')
			{
				if (map[len-- - 1] == 'b')
				{
					if (map[len-- - 1] == '.')
						return (1);
				}
				return (0);
			}
			return (0);
		}
		return (0);
	}
	return (0);
}
