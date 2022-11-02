/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:09:45 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/02 08:47:01 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	init_struct(t_struct *data, int argc, char **argv, char **env)
{
	data->argv = argv;
	data->argc = argc;
	data->env = env;
	data->find_good_path = FALSE;
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
	Je verifie que mes fd sont correct.
	Si which_fd est égal à "fd_in" je m'assure qu'il existe.
	Si which_fd est égal à "fd_out" je m'assure qu'il existe et je supprime ce
	qu'il contient, sinon je le créé. Et enfin je lui donne les authorisation
	d'écriture et de lecture pour le propriétaire.
*/
void	check_fd(t_struct *data, char **argv, char *which_fd)
{
	if (ft_strncmp(which_fd, "fd_in", 6) == 0)
	{
		data->fd_in = open(argv[1], O_RDONLY);
		if (data->fd_in == -1)
		{
			write(2, "Error\n", 6);
			close_pipe(data);
			explore_and_free(data);
			exit (1);
		}
		close(data->fd_in);
		data->fd_in = open(argv[1], O_RDONLY);
	}
	else if (ft_strncmp(which_fd, "fd_out", 7) == 0)
	{
		data->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->fd_out == -1)
		{
			write(2, "Error\n", 6);
			close_pipe(data);
			explore_and_free(data);
			exit (1);
		}
	}
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
