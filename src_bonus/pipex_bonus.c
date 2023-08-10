/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:35 by mbertin           #+#    #+#             */
/*   Updated: 2023/01/31 14:25:20 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_struct	*data;

	if (argc >= 5 && env)
	{
		calloc_struct(&data);
		init_struct(data, argc, argv, env);
		if (ft_strncmp("here_doc", argv[1], 9) == 0)
			heredoc(data);
		find_and_split_path(data);
		path_with_slash(data);
		piping(data);
		fork_and_execute(data);
		close_pipe(data);
		close(data->fd_in);
		close(data->fd_out);
		explore_and_free(data);
		if (data->heredoc_delimiter == TRUE)
			unlink("temp_heredoc");
	}
	else
	{
		write(2, "Error.\n", 7);
		exit(1);
	}
	return (0);
}

void	heredoc(t_struct *data)
{
	int		temp;
	char	*str;

	temp = open("temp_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (data->heredoc_delimiter == FALSE)
	{
		ft_putstr_fd("HEREDOC >", STDIN_FILENO);
		str = get_next_line(STDIN_FILENO, data);
		if (str == NULL)
		{
			free (str);
			break ;
		}
		if (ft_strncmp(str, data->argv[2], ft_strlen(data->argv[2] + 1)) == 0
			&& ft_strlen(str) == ft_strlen(data->argv[2]) + 1)
			data->heredoc_delimiter = TRUE;
		else
			ft_putstr_fd(str, temp);
		free(str);
	}
	free (data->buffer);
	close (temp);
	temp = dup(STDIN_FILENO);
	close (temp);
}
/*

check longeur de end of file delimiter.

-	./pipex file_in "/usr/bin/cat" "wc -l" file
	Corriger si le chemin n'est pas bon dans argv[j].

*/
// data->status = ft_calloc(sizeof(int), argc - 1);
// data->res_wait = ft_calloc(sizeof(int), argc - 1);

/*
	PIPING :

	Je fais un pipe pour chaque commande qui doivent communiquer entre elle,
	donc par exemple si jai 2 commande, j'ai un seul pipe. Si j'ai 3 commande
	j'ai 2 pipes et ainsi de suite.

	FORKING :

	J'ai 1 fork par commande. Par exemple pour cat et wc, je vais pouvoir
	envoyer le resulat de cat dans un pipe qui va être recupéré par un processus
	fils. Ce processus fils va alors executer la commande wc et dupliquer le
	resultat dans mon fichier fichier_out.txt




------------------------------- SÉCURITÉ --------------------------------------

- S'assurer que le programme fonctionne si on me donne en argument
	"./pipex fichier1 "/bin/usr/ls" wc fichier2"


	1. Je déclare une variable `status` pour la donner en paramètre à `wait`

	2. Je déclare une variable `res_wait` pour récupérer la valeur de retour
	de `wait`

	3. J’appel `wait` DANS le processus du père (if pid > 0) pour suspendre
	l’exécution du processus parent jusqu’à ce que l’état de son fils change
	et je stock sa valeur de retour dans `res_wait`. La valeur de retour est
	 le status du fils.

	4. Dans un `if`, j’appel `WIFEXITE(status)` qui va me servir à analyser la
	variable `status` et déterminer si le processus du fils c’est bien terminé.
	 Si la valeur de retour == 1 alors la processus c’est terminé.

	étant donné que plusieurs processus auront lieu en même temps, la valeur de
	status et res_wait seront différent pour chaque boucle car il ne s’agit pas
	du processus père. Bien sur il faut s’assurer que chaque appel de status et
	res_wait ce fait bien dans le processus père (if pid > 0)



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

-	Avant tout, il va falloir découper variable PATH (avec les fonctions
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
