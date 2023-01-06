/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:17:18 by murdemir          #+#    #+#             */
/*   Updated: 2023/01/06 17:35:46 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_format(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_putchar (va_arg (ap, int)));
	else if (format == 's')
		return (ft_putstr (va_arg (ap, char *)));
	else if (format == 'p')
	{
		ft_putstr ("0x");
		return (ft_putpointer (va_arg (ap, void *)) + 2);
	}
	else if (format == 'd' || format == 'i')
		return (ft_putnbr (va_arg (ap, int)));
	else if (format == 'u')
		return (ft_putunint (va_arg (ap, unsigned int)));
	else if (format == 'x')
		return (ft_puthex (va_arg (ap, unsigned int), 'x'));
	else if (format == 'X')
		return (ft_puthex (va_arg (ap, unsigned int), 'X'));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(ap, format[i + 1]);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
