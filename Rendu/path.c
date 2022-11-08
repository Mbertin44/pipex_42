/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:35:11 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/08 16:33:33 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

/*
	Je cherche PATH dans mon tableau env. Quand je trouve "PATH" je vais
	diviser le string dans mon tableau **split_path à chaque fois que je tombe
	sur ':'.

	La variable PATH contient le chemin des differentes commandes shell séparé
	par des ":"

*/
void	find_and_split_path(t_struct *data)
{
	int		i;
	int		j;
	char	*full_path;

	i = 0;
	j = 0;
	data->cmd_count = data->argc - 3;
	while (data->env[j])
		j++;
	while (i < j)
	{
		if (ft_strnstr(data->env[i], "PATH=", 5) != NULL)
		{
			data->env_path = TRUE;
			break ;
		}
		i++;
	}
	if (data->env_path != TRUE)
		error_and_exit();
	full_path = ft_substr(data->env[i], 5, ft_strlen(data->env[i]));
	data->split_path = ft_split(full_path, ':');
	free (full_path);
}

/*
	Dans mon tableau split_path qui contient les différents chemin pour mes
	commandes shell, je vais ajouter un "/" à la fin de chaque élément du
	tableau pour que les chemins soit correct.
*/
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

/*
	Je vais diviser ma commande qui est dans argv[j] quand je tombe sur un
	espace
*/
void	check_path(t_struct *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->path_name[i++])
	{
		temp = ft_strjoin(data->path_name[i], data->cmd->split_cmd[0]);
		if (access(temp, F_OK | X_OK) == 0)
		{
			if (data->good_path)
				free(data->good_path);
			data->good_path = temp;
			data->find_good_path = TRUE;
			break ;
		}
		free(temp);
	}
	i = 0;
}

void	check_access(t_struct *data, int j)
{
	int	i;

	i = 0;
	if (data->good_path)
		free(data->good_path);
	data->cmd->split_cmd = ft_split(data->argv[j], ' ');
	if (access(data->cmd->split_cmd[0], F_OK | X_OK) == 0)
		execve(data->cmd->split_cmd[0], data->cmd->split_cmd, data->env);
	else
	{
		check_path(data);
		execve(data->good_path, data->cmd->split_cmd, data->env);
	}
	if (data->find_good_path == FALSE)
		good_path_is_false(data);
}

// void	check_access(t_struct *data, int j)
// {
// 	int	i;

// 	i = 0;
// 	if (data->good_path)
// 		free(data->good_path);
// 	if (access(data->argv[j], F_OK | X_OK) != 0
// 		&& ft_strchr(data->argv[j], '/') == 0)
// 	{
// 		data->cmd->split_cmd = ft_split(data->argv[j], ' ');
// 		check_path(data);
// 	}
// 	else if (access(data->argv[j], F_OK | X_OK) == 0)
// 	{
// 		split_path_and_cmd(data, j, i);
// 		check_path(data);
// 	}
// 	if (data->find_good_path == FALSE)
// 		good_path_is_false(data);
// }
