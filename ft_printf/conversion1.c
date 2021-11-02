/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:23 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/02 15:53:53 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int c, int fd)
{
	return (write(fd, &(char)c, 1));
}

int	ft_putstr_fd(char *str, int fd)
{
	int	index;

	index = 0;
	while (str[index])
		index += ft_putchar(str[index], fd);
	return (index);
}

int	ft_putaddr_fd(
