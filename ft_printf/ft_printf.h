/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:15:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/03 12:23:01 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *str, int fd);
int	ft_putaddr_fd(unsigned int addr, int fd);
int	ft_putunbr_fd(int nb, int fd);
int	ft_putnbr_fd(int nb, int fd);
int	ft_printhexa(unsigned int nb, int fd);
int	ft_printhexam(unsigned int nb, int fd);
int	ft_isconv(char c, char *str);

#endif
