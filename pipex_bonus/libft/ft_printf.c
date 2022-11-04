/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:59:36 by mbertin           #+#    #+#             */
/*   Updated: 2022/07/14 15:12:12 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg(const char *str, va_list params, int *len)
{
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(params, int), len);
	if (*str == 'c')
		ft_putchar((unsigned char)va_arg(params, int), len);
	if (*str == 's')
		ft_putstr(va_arg(params, char *), len);
	if (*str == 'x' || *str == 'X')
		ft_puthex(va_arg(params, unsigned int), len, *str, 16);
	if (*str == 'u')
		ft_puthex(va_arg(params, unsigned int), len, *str, 10);
	if (*str == 'p')
	{
		*len += 2;
		write(1, "0x", 2);
		ft_puthex(va_arg(params, unsigned long), len, *str, 16);
	}
	if (*str == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	params;

	len = 0;
	va_start(params, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_printf_arg(&format[++i], params, &len);
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(params);
	return (len);
}
