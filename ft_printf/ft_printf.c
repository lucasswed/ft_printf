/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:24:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/09 10:56:42 by lucas-ma         ###   ########.fr       */
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
		return (ft_putaddr_fd(va_arg(ap, unsigned long), 1));
	if (**fmt == 'd' || **fmt == 'i')
		return (ft_putnbr_base(va_arg(ap, int), 10, 1, 1));
	if (**fmt == 'u')
		return (ft_putunbr_base(va_arg(ap, unsigned int), 10, 1, 1));
	if (**fmt == 'x')
		return (ft_putunbr_base(va_arg(ap, unsigned int), 16, 1, 1));
	if (**fmt == 'X')
		return (ft_putunbr_base(va_arg(ap, unsigned int), 16, 1, 0));
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
			count += write(1, fmt, 1);
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
