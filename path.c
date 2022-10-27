/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:35:11 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/26 17:14:27 by mbertin          ###   ########.fr       */
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
	char	*full_path;

	i = 0;
	data->cmd_count = data->argc - 3;
	while (ft_strnstr(data->env[i], "PATH=", 5) == NULL)
		i++;
	full_path = ft_substr(data->env[i], 5, ft_strlen(data->env[i]));
	data->split_path = ft_split(full_path, ':');
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
void	check_path(t_struct *data, int j)
{
	int		i;
	char	*temp;

	i = 0;
	data->cmd->split_cmd = ft_split(data->argv[j], ' ');
	while (data->path_name[i])
	{
		temp = ft_strjoin(data->path_name[i], data->cmd->split_cmd[0]);
		if (access(temp, F_OK | X_OK) == 0)
		{
			if (data->good_path)
				free(data->good_path);
			data->good_path = temp;
			break ;
		}
		free(temp);
		i++;
	}
}
