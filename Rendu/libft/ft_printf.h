/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:19:18 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/15 08:48:18 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

void	ft_putstr(char *str, int *len);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
void	ft_puthex(unsigned long n, int *len, char str, size_t base);

#endif