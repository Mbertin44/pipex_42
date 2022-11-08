/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:12 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/08 16:13:24 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

/*
	Je calloc un double array de int pour pouvoir stock mes différent pipes,
	puis je malloc chaque ligne de ce doubleau pour pouvoir récuperer les
	extrémité de chaque pipe (data->pipe[0][0] et data->pipe[0][1] pour les
	deux extrémité de mon premier pipe)
*/

void	piping(t_struct *data)
{
	int	i;

	i = 0;
	data->pipe = ft_calloc(sizeof(int *), (data->cmd_count - 1));
	if (!data->pipe)
		error_and_exit();
	while (i < data->cmd_count - 1)
	{
		data->pipe[i] = ft_calloc(sizeof(int), 2);
		if (pipe(data->pipe[i]) == -1)
			error_and_exit();
		i++;
	}
}

/*
	Pour chaque commande je crée un processus grace à fork. Dans chaque fork je
	redirige l'entrée et la sortie standart, je close l'ancien fd puis je
	cherche à executer la commande de argv (je vais surement isoler
	ces commandes à un moment). Une fois la commande exécuter le processus fini
	de passer a travers mon programme. fork_count s'incrémente et donc je
	retourne dans ma boucle et je cherche à executer la prochaine commande en
	récupérant le contenu du pipe.
*/
void	fork_and_execute(t_struct *data)
{
	int	j;

	j = 2;
	while (data->fork_count < data->cmd_count)
	{
		data->pid = fork();
		if (data->pid == -1)
			error_and_exit();
		else if (data->pid == 0)
		{
			check_redirection(data);
			close_pipe(data);
			check_access(data, j);
			exit(EXIT_FAILURE);
		}
		j++;
		data->fork_count++;
	}
}
