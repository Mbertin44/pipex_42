/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:19:45 by mbertin           #+#    #+#             */
/*   Updated: 2022/08/07 12:56:25 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*tab;

	if (nbr == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	tab = malloc(nbr * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nbr * size);
	return (tab);
}
