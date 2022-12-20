/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:41:31 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/19 04:45:29 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verfication(char c, va_list format)
{
	if (c == 'c')
		return (ft_putchar(va_arg(format, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(format, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(format, int)));
	else if (c == 'X')
		return (hexa((unsigned int)va_arg(format, unsigned int), 16, 1));
	else if (c == 'x')
		return ((unsigned int)hexa(va_arg(format, unsigned int), 16, 0));
	else if (c == 'u')
		return (ft_unsigne_value(va_arg(format, int)));
	else if (c == '%')
		write(1, "%", 1);
	else if (c == 'p')
	{	
		write(1, "0x", 2);
		return (hexa((unsigned long long)
				va_arg(format, unsigned long long), 16, 0) + 2);
	}
	return (1);
}

int	cas(const char *s, int *i)
{
	int	j;

	j = 2;
	write(1, "%", 1);
	write(1, &s[*i], 1);
	return (j);
}

int	case2(int *i, const char *s)
{
	*i += 1;
	if (s[*i] == 'd' || s[*i] == 'c' || s[*i] == 's' || s[*i] == 'X'
		|| s[*i] == 'i' || s[*i] == 'x' || s[*i] == 'u'
		|| s[*i] == '%' || s[*i] == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	format;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(format, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (case2(&i, s) == 1)
			{
				j += verfication(s[i], format);
			}
			else
				j += cas(s, &i);
		}
		else
			j += write(1, &s[i], 1);
		i++;
	}
	va_end(format);
	return (j);
}
