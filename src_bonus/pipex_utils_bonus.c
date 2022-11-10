/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:09:45 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/08 16:33:14 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init_struct(t_struct *data, int argc, char **argv, char **env)
{
	data->argv = argv;
	data->argc = argc;
	data->env = env;
	data->env_path = FALSE;
	data->find_good_path = FALSE;
	data->fork_count = 0;
	data->heredoc_delimiter = FALSE;
}

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

/*
	Pour chaque pipe (Mon nombre de pipe est égal aux nombre de commande - 1)
	je ferme la partie écriture et écriture de ce dernier. Ici mon index i
	dans la boucle while représente mes pipes.
*/
void	close_pipe(t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_count - 1)
	{
		close(data->pipe[i][0]);
		close(data->pipe[i][1]);
		i++;
	}
}
