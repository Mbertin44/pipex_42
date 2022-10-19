/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:35 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/18 15:50:23 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int			i;
	t_struct	*var;
	char		*temp;

	i = 0;
	var = calloc(sizeof(t_struct), 1);
	if (!var)
		exit (1);
	(void)argc;
	(void)argv;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	temp = ft_substr(env[i], 5, ft_strlen(env[i]));
	var->path = ft_split(temp, ':');
	i = 0;
	while (var->path[i])
	{
		var->path_name[i] = ft_strjoin(var->path[i], "/");
		printf("%s\n", var->path_name[i]);
		i++;
	}
	var->good_path = check_path(var);
	// execve("/bin/ls", options, env);
	return (0);
}

char	*check_path(t_struct *var)
{
	int		i;
	char	*temp;

	i = 0;
	while (var->path_name[i])
	{
		temp = ft_strjoin(var->path_name[i], var->argv[2]);
		if (access(temp, F_OK | X_OK) == 0)
			return (temp);
		i++;
	}
	return ("good_path not find\n");
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

	envp[], ou « environment pointer » , c’est un pointeur vers les variables
	d’environnement spécifiques à chaque ordinateur. Elle contient beaucoup
	d’informations à propos du système, y compris une variable qui va beaucoup
	nous intéresser pour trouver le premier paramètre de la
	fonction execve: PATH.

-	int access(const char *path, int mode);
	access(var->path_name[i], F_OK | X_OK);
	X_OK for execute/search permission), or the existence test (F_OK).

-	Pour voir le chemin d'une commande : which "commande" ou alors type
	-a "commande"

-	// extern char **environ;

-	Avant tout, il va falloir découper cette variable PATH (avec les fonctions
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