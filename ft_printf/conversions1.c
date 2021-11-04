/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:23 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/04 22:44:24 by lucasSilv        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *str, int fd)
{
	int	index;

	if (!str)
		return (write(fd, "(null)", 6));
	index = 0;
	while (str[index])
		index += ft_putchar_fd(str[index], fd);
	return (index);
}

int	ft_putaddr_fd(unsigned int addr, int fd)
{
	if (!addr)
		return (write(fd, "0x0", 3));
	return (write(fd, "0x", 2) + ft_printhexa(addr, fd));
}

int	ft_putunbr_base(size_t nb, int len_base, char *base, int fd)
{
	static int	count;

	count = 0;
	if (nb < len_base)
		count += write(1, base + num, 1);
	else
	{
		ft_putnbr_base(nb / len_base, len_base, base, fd);
		nb = nb % len_base;
		count += write(1, base + nb, 1);
	}
}
