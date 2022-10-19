/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:23:32 by mbertin           #+#    #+#             */
/*   Updated: 2022/04/20 13:50:25 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	temp = ft_strdup((char *)s);
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		temp[i] = f(i, temp[i]);
		i++;
	}
	return (temp);
}
