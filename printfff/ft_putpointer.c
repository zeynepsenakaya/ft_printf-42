/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zekaya <zekaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:31:13 by zekaya            #+#    #+#             */
/*   Updated: 2023/01/06 17:31:28 by zekaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	unsigned long	ret;
	int				len;

	ret = (unsigned long)ptr;
	len = 0;
	if (ret > 15)
		len += ft_putpointer((void *)(ret / 16));
	len += ft_putchar("0123456789abcdef"[ret % 16]);
	return (len);
}
