/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:23 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/05 14:43:41 by lucas-ma         ###   ########.fr       */
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

int	ft_putaddr_fd(unsigned long addr, int fd)
{
	if (!addr)
		return (write(fd, "0x0", 3));
	return (write(fd, "0x", 2) + ft_putunbr_base(addr, 16, fd, 1));
}

int	ft_putnbr_base(ssize_t nb, size_t len_base, int fd, int type)
{
	int		count;

	count = 0;
	if (nb == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nb < 0)
	{
		count += ft_putchar_fd('-', 1);
		nb = -nb;
	}
	return (count + ft_putunbr_base(nb, len_base, fd, type));
}
