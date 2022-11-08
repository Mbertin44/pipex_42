/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:23:14 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/07 12:29:22 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

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
		check_fd_in(data, argv);
	else if (ft_strncmp(which_fd, "fd_out", 7) == 0)
		check_fd_out(data, argv);
}

void	check_fd_in(t_struct *data, char **argv)
{
	if (data->heredoc_delimiter == TRUE)
		data->fd_in = open("temp_heredoc", O_RDONLY);
	else
		data->fd_in = open(argv[1], O_RDONLY);
	if (data->fd_in == -1)
	{
		close_pipe(data);
		explore_and_free(data);
		error_and_exit();
	}
}

void	check_fd_out(t_struct *data, char **argv)
{
	if (data->heredoc_delimiter == TRUE)
	data->fd_out = open(argv[data->argc -1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
	data->fd_out = open(argv[data->argc -1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
	{
		close_pipe(data);
		explore_and_free(data);
		error_and_exit();
	}
}
