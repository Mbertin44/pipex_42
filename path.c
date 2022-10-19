/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:35:11 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/19 14:55:59 by mbertin          ###   ########.fr       */
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

void	path_with_slash(t_struct *data)
{
	int	i;

	i = 0;
	i = size_of_array(data->split_path);
	data->path_name = ft_calloc(sizeof(char *), i + 1);
	if (!data->path_name)
		exit (1);
	i = 0;
	while (data->split_path[i])
	{
		data->path_name[i] = ft_strjoin(data->split_path[i], "/");
		i++;
	}
}

void	*check_path(t_struct *data, char **argv)
{
	int		i;
	char	*temp;

	data->argv = argv;
	i = 0;
	data->cmd->split_cmd = ft_split(data->argv[1], ' ');
	while (data->path_name[i])
	{
		temp = ft_strjoin(data->path_name[i], data->cmd->split_cmd[0]);
		if (access(temp, F_OK | X_OK) == 0)
		{
			data->good_path = temp;
			break ;
		}
		i++;
	}
	return (0);
}
