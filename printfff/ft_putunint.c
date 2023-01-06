/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:34:15 by zekaya            #+#    #+#             */
/*   Updated: 2023/01/06 17:35:48 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unintlen(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	ft_putunint(unsigned int number)
{
	int	i;

	i = ft_unintlen(number);
	if (number > 9)
	{
		ft_putunint(number / 10);
		ft_putunint(number % 10);
	}	
	else
		ft_putchar(number + '0');
	return (i);
}
