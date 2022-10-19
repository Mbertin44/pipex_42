/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:35 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/19 16:47:22 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_struct	*data;

	(void)argc;
	data = NULL;
	calloc_struct(&data);
	find_and_split_path(data, env);
	path_with_slash(data);
	check_path(data, argv);
	printf("%s\n", data->good_path);
	a_son_is_born();
	// execve(data->good_path, data->cmd->split_cmd, env);
	return (0);
}

void	a_son_is_born()
{
	pid_t	pid;

	printf("fork\n");
	pid = fork();
	if (pid == -1)
	{
		printf("Le fils n'est pas née :/\n");
		exit (1);
	}
	if (pid == 0)
	{
		printf("Salut papa, c'est moi ton fils\n");
		usleep(1000000);
		printf("Gamin : DONE\n");
	}
	else if (pid > 0)
	{
		printf("C'est moi le daron\n");
		printf("Daron : DONE\n");
	}
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

-	// extern char **environ;

-	Avant tout, il va falloir découper cette dataiable PATH (avec les fonctions
	ft_strnstr,	ft_substr et ft_split de la libft !) en utilisant « : » comme
	délimiteur.

	- strnstr pour chercher PATH dans mon tableau **env
	- substr pour enlever PATH de la string
	- split avec ":" comme délimiteur pour isoler chaque chemin de mes commandes

	- Utiliser acces qui prend le path en parametre, F_OK pour savoir
	si ca existe et IF_ pour savoir si ca s'execute. Si tous ce passe bien il
	renvoie 0 sinon il renvoie -1

	./pipex "ls -la"

-	Pour voir le procéssus : ps -e

-	ATTENTION : NE PAS CONFONDRE LE PID (IDENTIFIANT DU PROCESSUS FOURNI GRACE À
	LA VALEUR DE RETOUR DE FORK) ET LE CODE DE SORTIE (VALEUR DE RETOUR DE
	WEXITSTATUS).

	LE CODE DE SORTIE FOURNI PAR WEXITSTATUS ME SERA UTILE POUR L'EXECUTION DE
	WAITPID
-------------------- PROBLÈMES ---------------------

	-
*/