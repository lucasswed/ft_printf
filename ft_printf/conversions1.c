/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:23 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/03 12:16:28 by lucas-ma         ###   ########.fr       */
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

int	ft_putunbr_fd(int nb, int fd)
{
	int	count;

	count = 0;
	if (nb <= 9)
		count += ft_putchar_fd((nb + '0'), fd);
	else
	{
		ft_putunbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10 + '0'), fd);
	}
	return (count);
}

int	ft_putnbr_fd(int nb, int fd)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count += write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			count += ft_putchar_fd('-', fd);
			nb = -nb;
		}
	}
	return (count + ft_putunbr_fd(nb, fd));
}
