/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:24:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/04 08:36:48 by lucasSilv        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(char **fmt, va_list ap)
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
	if (**fmt == '%')
		return (ft_putchar_fd(**fmt, 1));
	return (1);
}

static int	ft_printf_main(va_list	ap, char *fmt)
{
	int	count;

	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (ft_isconv(*fmt, "cspdiuxX%"))
				count += ft_conversion(&fmt, ap);
			else
				return (count);
		}
		else
		{
			write(1, fmt, 1);
			count++;
		}
		fmt++;
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
	count = ft_printf_main(ap, (char *)fmt);
	va_end(ap);
	return (count);
}
