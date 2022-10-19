/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:09:45 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/19 14:10:27 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	calloc_struct(t_struct **data)
{
	*data = ft_calloc(1, sizeof(t_struct));
	if (!*data)
		exit (1);
	(*data)->cmd = ft_calloc(1, sizeof(t_cmd));
	if (!(*data)->cmd)
		exit (1);
}

int	size_of_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
