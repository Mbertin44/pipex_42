/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:35:11 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/19 09:42:01 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	find_and_split_path(t_struct *data, char **env)
{
	int		i;
	char	*full_path;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	full_path = ft_substr(env[i], 5, ft_strlen(env[i]));
	data->split_path = ft_split(full_path, ':');
}

int	size_of_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*check_path(t_struct *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->path_name[i])
	{
		temp = ft_strjoin(data->path_name[i], data->argv[1]);
		if (access(temp, F_OK | X_OK) == 0)
			return (temp);
		i++;
	}
	return ("good_path not find\n");
}