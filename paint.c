/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:48:11 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 00:18:53 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	incrimentation(t_long *so_long)
{
	so_long->x++;
	so_long->j = 0;
	so_long->n = so_long->n + 50;
	so_long->i = 0;
}

void	special_case(char *s, int i, t_long *so_long)
{
	if (s[i] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->wall, so_long->j, so_long->n);
	if (s[i] == 'C' || s[i] == 'P' || (s[i] == 'E'
			&& so_long->coin_number != 0)
		|| (s[i] == 'E' && so_long->coin_number == 0)
		|| s[i] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->background, so_long->j, so_long->n);
	if (s[i] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->coin, so_long->j, so_long->n);
}

void	windows_paint(int i, t_long *so_long, int fd)
{
	char	*s;

	so_long->coin_number = coin_counter(so_long, so_long->maps_tab);
	s = get_next_line(fd);
	while (s[i])
	{
		special_case(s, i, so_long);
		if (s[i] == 'P')
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
				so_long->pac, so_long->j, so_long->n);
		else if (s[i] == 'E' && so_long->coin_number != 0)
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
				so_long->door, so_long->j, so_long->n);
		else if (s[i] == 'E' && so_long->coin_number == 0)
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
				so_long->door_open, so_long->j, so_long->n);
		i++;
		so_long->j = so_long->j + 50;
	}
	incrimentation(so_long);
	free (s);
}
