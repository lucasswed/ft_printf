/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:24:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/03 12:22:49 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char **fmt, va_list ap)
{
	if (**fmt == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	if (**fmt == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	if (**fmt == 'p')
		return (ft_putaddr_fd(va_arg(ap, unsigned int), 1));
	if (**fmt == 'd' || **fmt == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	if (**fmt == 'u')
		return (ft_putunbr_fd(va_arg(ap, unsigned int), 1));
	if (**fmt == 'x')
		return (ft_printhexa(va_arg(ap, unsigned int), 1));
	if (**fmt == 'X')
		return (ft_printhexam(va_arg(ap, unsigned int), 1));
	return (1);
}

static int	ft_printf_main(va_list	ap, const char *fmt)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			index++;
			if (ft_isconv(fmt[index], "cspdiuxX"))
				count += ft_conversion(&fmt, ap);
			else
				count += ft_putchar_fd(fmt[index], 1);
		}
		index++;
		count++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	if (!fmt)
		return (-1);
	count = 0;
	va_start(ap, fmt);
	count = ft_printf_main(ap, fmt);
	va_end(ap);
	return (count);
}
