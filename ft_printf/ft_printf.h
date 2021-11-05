/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:15:47 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/11/05 14:36:58 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putaddr_fd(unsigned long addr, int fd);
int		ft_putunbr_base(size_t nb, size_t len_base, int fd, int type);
int		ft_putnbr_base(ssize_t nb, size_t len_base, int fd, int type);
int		ft_isconv(char c, char *str);
void	ft_strcpy(char *dst, const char *src, size_t n);

#endif
