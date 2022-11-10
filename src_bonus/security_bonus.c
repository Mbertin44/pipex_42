/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:56:43 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/10 09:18:30 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	explore_and_free(t_struct *data)
{
	free_double_array_char(data->split_path);
	free(data->split_path);
	free_double_array_char(data->path_name);
	free(data->path_name);
	free(data->good_path);
	free_double_array_int(data->pipe, data);
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

void	free_double_array_int(int **array, t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_count - 1)
	{
		free(array[i]);
		i++;
	}
}

void	good_path_is_false(t_struct *data)
{
	int	i;

	i = 0;
	write(2, "Error. Can't find the path of the command.\n", 43);
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
	write(2, "Error and exit.\n", 16);
	exit(EXIT_FAILURE);
}
