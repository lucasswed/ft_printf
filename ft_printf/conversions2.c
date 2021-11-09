/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:09:57 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/09 10:58:37 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_base(size_t nb, size_t len_base, int fd, int type)
{
	static int	count;
	char		base[17];

	count = 0;
	if (len_base == 16)
	{
		if (type == 1)
			ft_strcpy(base, "0123456789abcdef", 16);
		else
			ft_strcpy(base, "0123456789ABCDEF", 16);
	}
	else
		ft_strcpy(base, "0123456789", 10);
	if (nb < len_base)
		count += ft_putchar_fd(base[nb], 1);
	else
	{
		ft_putunbr_base(nb / len_base, len_base, fd, type);
		nb = nb % len_base;
		count += ft_putchar_fd(base[nb], 1);
	}
	return (count);
}

int	ft_isconv(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_strcpy(char *dst, const char *src, size_t n)
{
	if (dst && src)
	{
		while (n--)
			*dst++ = *src++;
	}
}
