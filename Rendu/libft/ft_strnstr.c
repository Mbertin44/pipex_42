/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:50:13 by mbertin           #+#    #+#             */
/*   Updated: 2022/04/15 14:34:17 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *found, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (found[i] == '\0')
		return ((char *)str);
	while (i < n && str[i] != '\0')
	{
		j = 0;
		while (i + j < n && str[i + j] == found[j])
		{
			if (found[j + 1] == '\0')
				return ((char *) str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
