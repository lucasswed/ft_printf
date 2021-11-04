/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:09:57 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/04 09:12:01 by lucasSilv        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if (nb < 16)
		count += ft_putchar_fd("0123456789abcdef"[nb], 1);
	else
	{
		ft_printhexa(nb / 16, fd);
		nb = nb % 16;
		count += ft_putchar_fd("0123456789abcdef"[nb], 1);
	}
	return (count);
}

int	ft_printhexam(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if (nb < 16)
		count += ft_putchar_fd("0123456789ABCDEF"[nb], 1);
	else
	{
		ft_printhexam(nb / 16, fd);
		nb = nb % 16;
		count += ft_putchar_fd("0123456789ABCDEF"[nb], 1);
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
