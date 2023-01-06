/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:32:25 by zekaya            #+#    #+#             */
/*   Updated: 2023/01/06 17:37:15 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int number)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(number);
	len += ft_putstr(str);
	free(str);
	return (len);
}
