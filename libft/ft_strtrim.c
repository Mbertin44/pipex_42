/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:41:42 by mbertin           #+#    #+#             */
/*   Updated: 2022/04/20 13:51:09 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *src, char const *set)
{
	int	end;

	if (!src || !set)
		return (NULL);
	while (*src && ft_strchr(set, *src))
		src++;
	end = ft_strlen(src);
	while (end && ft_strchr(set, src[end]))
	{
		end--;
	}
	return (ft_substr(src, 0, end + 1));
}
