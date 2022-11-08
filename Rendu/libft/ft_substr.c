/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:18:21 by mbertin           #+#    #+#             */
/*   Updated: 2022/04/22 14:52:46 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*temp;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (len > slen)
		temp = ft_calloc((slen + 1), sizeof(char));
	else
		temp = ft_calloc((len + 1), sizeof(char));
	if (!temp)
		return (NULL);
	if (start >= slen)
		return (temp);
	i = -1;
	while (++i < len && s[i])
		temp[i] = s[start + i];
	temp[i] = '\0';
	return (temp);
}
