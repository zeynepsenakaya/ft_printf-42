/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:35:23 by zekaya            #+#    #+#             */
/*   Updated: 2023/01/06 17:37:08 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int number, const char format)
{
	int	len;

	len = hex_len(number);
	if (number >= 16)
	{
		ft_puthex(number / 16, format);
		ft_puthex(number % 16, format);
	}
	else
	{
		if (format == 'x')
			ft_putchar("0123456789abcdef"[number % 16]);
		else if (format == 'X')
			ft_putchar("0123456789ABCDEF"[number % 16]);
	}
	return (len);
}
