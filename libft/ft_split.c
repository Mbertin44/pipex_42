/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:39:53 by mbertin           #+#    #+#             */
/*   Updated: 2022/04/22 13:03:58 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	ft_count_word(char const *src, char sep)
{
	int	words;

	words = 0;
	while (*src)
	{
		while (*src == sep)
			src++;
		if (*src != sep && *src)
			words++;
		while (*src != sep && *src)
			src++;
	}
	return (words);
}

char	**ft_split(char const *src, char sep)
{
	char	**tab;
	int		words;
	int		i;
	int		len;

	if (!src)
		return (NULL);
	words = ft_count_word(src, sep);
	tab = ft_calloc(sizeof(char *), (words + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		while (*src && *src == sep)
			src++;
		if (ft_strchr(src, sep))
			len = ft_strchr(src, sep) - src;
		else
			len = ft_strlen(src);
		tab[i] = ft_substr(src, 0, len);
		src += len;
	}
	return (tab);
}
