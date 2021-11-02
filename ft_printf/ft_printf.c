/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:24:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/02 11:05:00 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 'c')
				ft_print_char(va_arg(ap, int));
			else if (*(fmt + 1) == 's')
				ft_print_string(va_arg(ap, char *));
			else if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i')
				ft_print_number(va_arg(ap, int));
			else if (*(fmt + 1) == 'u')
				ft_print_unsigned(va_arg(ap, unsigned int));
			else if (*(fmt + 1) == 'x' || *(fmt + 1) == 'X')
				ft_print_hexa(va_arg(ap, int));
			else if (*(fmt + 1) == 'p')
				ft_print_void(va_arg(ap, void *));
			else if (*(fmt + 1) == '%')
				ft_putchar_fd('%', 1);
		}
		ft_putchar_fd(*fmt, 1);
		i++;
	}
	return (i);
}
