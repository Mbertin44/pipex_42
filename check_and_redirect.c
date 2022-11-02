/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:56:40 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/01 12:45:06 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

/*
	Selon le child process ou je me trouve je vais vouloir modifier STDIN ou
	STDOUT. Si je suis dans mon premier child process je dois verifier que le
	fd qui va devenir le nouveau STDIN existe bien. Si c'Est le cas je modifie
	STDIN et STDOUT.

*/
void	check_redirection(t_struct *data)
{
	if (data->fork_count == 0)
	{
		check_fd(data, data->argv, "fd_in");
		redirection(data->fd_in, data->pipe[0][1]);
		close(data->fd_in);
	}
	else if (data->fork_count + 1 < data->cmd_count)
		redirection(data->pipe[data->fork_count - 1][0],
			data->pipe[data->fork_count][1]);
	else if (data->fork_count == data->cmd_count - 1)
	{
		check_fd(data, data->argv, "fd_out");
		redirection(data->pipe[data->fork_count - 1][0], data->fd_out);
		close(data->fd_out);
	}
}

/*
	CEST PAS "LE NOUVEAU REMPLACE LANCIEN" !
	C'EST "CELUI-CI DEVIENT CELUI-LA" !

	Dans le cas du premier fork, je redirige EN AVANCE :

	1 - Mon fd_in DEVIENT le stdin et donc ma commande cat va aller chercher
	DANS fd_in a la place du stdin

	2 - Mon pipe[0][1] (1 = écriture, 0 = lecture) DEVIENT le STDOUT et donc
	l'affichage de la commande cat ne sera pas dans mon terminal mais dans mon
	pipe côté écriture.

	De ce fait dans mon prochain fork ma commande wc va aller chercher DANS LE
	PIPE. Mon pipe[0][0] (Côté lecture) deviens STDIN
	 et mon fichier_out devient stdout
*/
void	redirection(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}
