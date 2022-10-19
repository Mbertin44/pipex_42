/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:09:48 by mbertin           #+#    #+#             */
/*   Updated: 2022/04/20 13:49:23 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	j = 0;
	if (len_dst > dstsize || dstsize <= 0)
		return (dstsize + len_src);
	while (src[j] != '\0' && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len_src + len_dst);
}
