/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:36:58 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 04:45:29 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hexa(unsigned long long dec, int i, int flag)
{
	int	count;

	count = 0;
	if (dec < 0)
	{
		dec *= -1;
		count += ft_putchar('-');
	}
	if (dec >= (unsigned long long)i)
			count += hexa(dec / i, i, flag);
	if (flag == 0)
		count += ft_putchar(HEX[dec % i]);
	else
		count += ft_putchar(HEX_MAJ[dec % i]);
	return (count);
}
