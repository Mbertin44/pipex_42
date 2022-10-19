/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:41:24 by marvin            #+#    #+#             */
/*   Updated: 2022/04/25 11:42:15 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_intlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		i;
	int		sign;

	sign = 0;
	i = ft_intlen(n) - 1;
	temp = ft_calloc(ft_intlen(n) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(temp, "-2147483648", 11));
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (i >= 0)
	{
		temp[i] = n % 10 + '0';
		n /= 10;
		if (i == 0 && sign == 1)
			temp[i] = '-';
		i--;
	}
	return (temp);
}
