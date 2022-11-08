/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:35 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/08 16:56:55 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_struct	*data;

	if (argc == 5 && env)
	{
		calloc_struct(&data);
		init_struct(data, argc, argv, env);
		find_and_split_path(data);
		path_with_slash(data);
		piping(data);
		fork_and_execute(data);
		close_pipe(data);
		close(data->fd_in);
		close(data->fd_out);
		explore_and_free(data);
	}
	else
	{
		write(2, "Error.\n", 7);
		exit(1);
	}
	return (0);
}

/*
-------------------- COMMENTAIRE ---------------------

-	int execve(const char *pathname, char *const argv[], char *const envp[]);

	pathname, c’est le chemin d’accès aux fichiers binaires du programme
	qu’on veut exécuter. Pour voir le chemin d’accès de commandes shell,
	il suffit de tapper la commande which ls ou which grep, par exemple.

    argv[], c’est les options que l’on souhaite transmettre au programme,
	par exemple ls -l ou grep coucou (le nom du programme lui-même doit être
	inclus à l’index 0 du tableau).

	envp[], ou « environment pointer » , c’est un pointeur vers les dataiables
	d’environnement spécifiques à chaque ordinateur. Elle contient beaucoup
	d’informations à propos du système, y compris une dataiable qui va beaucoup
	nous intéresser pour trouver le premier paramètre de la
	fonction execve: PATH.

-	int access(const char *path, int mode);
	access(data->path_name[i], F_OK | X_OK);
	X_OK for execute/search permission), or the existence test (F_OK).

-	Pour voir le chemin d'une commande : which "commande" ou alors type
	-a "commande"

-	Pour voir le procéssus : ps -e

-	ATTENTION : NE PAS CONFONDRE LE PID (IDENTIFIANT DU PROCESSUS FOURNI GRACE À
	LA VALEUR DE RETOUR DE FORK) ET LE CODE DE SORTIE (VALEUR DE RETOUR DE
	WEXITSTATUS).

	LE CODE DE SORTIE FOURNI PAR WEXITSTATUS ME SERA UTILE POUR L'EXECUTION DE
	WAITPID

*/