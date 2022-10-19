/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:35 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/19 09:57:46 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int			i;
	t_struct	*data;

	i = 0;
	(void)argc;
	data = calloc(sizeof(t_struct), 1);
	if (!data)
		exit (1);
	data->argv = argv;
	find_and_split_path(data, env);
	i = size_of_array(data->split_path);
	data->path_name = ft_calloc(sizeof(char), i + 1);
	if (!data->path_name)
		exit (1);
	i = 0;
	while (data->split_path[i])
	{
		data->path_name[i] = ft_strjoin(data->split_path[i], "/");
		printf("%s\n", data->path_name[i]);
		i++;
	}
	data->good_path = check_path(data);
	printf("%s\n", data->good_path);
	// execve("/bin/ls", options, env);
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

-------------------- PROBLÈMES ---------------------

	-
*/