/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:01:43 by mbertin           #+#    #+#             */
/*   Updated: 2022/06/23 15:21:36 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 			PLUS A JOUR MAIS TOUJOURS VALABLE ( ligne 30 )

---> (*len)++;
Ici je dois mettre entre parenthese mon *len car je veux qu'il comprenne que je 
veux incrémenter la valeur du pointeur est non pas l'adresse. La lecture des 
règles ce fait de droit a gauche et le fais de désigner la valeur d'un pointeur 
ou d'incrémenter une valeur on la même priorité donc la syntaxe -> *len++ voulait
dire incrémente l'adresse delen puis désigné que je parle de la valeur de len et
 non pas son adresse. 

(*len)++ veut bien dire incrémente la valeur à l'adresse de len*/

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-n, len);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10, len);
		}
		ft_putchar(48 + n % 10, len);
	}
}

void	ft_puthex(unsigned long n, int *len, char str, size_t base)
{
	if (n >= base)
	{
		ft_puthex(n / base, len, str, base);
		ft_puthex(n % base, len, str, base);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'), len);
		else
		{
			if (str == 'x' || str == 'p')
				ft_putchar((n - 10 + 'a'), len);
			if (str == 'X')
				ft_putchar((n - 10 + 'A'), len);
		}
	}
}
