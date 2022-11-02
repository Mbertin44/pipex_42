/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:56:43 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/02 08:46:16 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	explore_and_free(t_struct *data)
{
	free_double_array_char(data->split_path);
	free(data->split_path);
	free_double_array_char(data->path_name);
	free(data->path_name);
	free(data->good_path);
	if (data->cmd_count > 2)
		free_double_array_int(data->pipe);
	else if (data->cmd_count == 2)
		free(data->pipe[0]);
	free(data->pipe);
	free(data->cmd);
	free(data);
}

void	free_double_array_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

void	free_double_array_int(int **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

void	good_path_is_false(t_struct *data)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (data->cmd->split_cmd[i])
	{
		free(data->cmd->split_cmd[i]);
		i++;
	}
	free(data->cmd->split_cmd);
	explore_and_free(data);
	exit (1);
}

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
