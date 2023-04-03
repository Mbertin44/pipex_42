<p align="center">
  <img src="https://user-images.githubusercontent.com/81205527/185808394-0045a614-600a-443d-add8-736951453ce3.png">
</p>

# Projet pipex

Le projet pipex est un projet de l'école 42 qui consiste à recréer le fonctionnement de la commande | dans un shell en utilisant les appels systèmes Unix pipe() et fork().

Le but du projet est de créer un programme qui prend en entrée deux commandes et les exécute de telle manière que la sortie de la première commande est redirigée en entrée de la seconde commande.

## Fonctionnalités disponibles

Le programme permet d'exécuter deux commandes en utilisant un pipeline et permet également de rediriger les entrées/sorties de chaque commande vers des fichiers.

Les fonctionnalités disponibles incluent :

* Exécution de deux commandes séparées par un espace
* Redirection de l'entrée d'une commande à partir d'un fichier
* Redirection de la sortie d'une commande vers un fichier
* Gestion des erreurs de manière appropriée

## Utilisation

Pour utiliser le programme, vous pouvez le compiler en utilisant le Makefile fourni. Une fois compilé, vous pouvez exécuter le programme en fournissant les arguments souhaités. Les arguments disponibles sont :

* Le nom du fichier d'entrée
* La première commande
* La deuxième commande
* Le nom du fichier de sortie

Voici un exemple d'utilisation :

`./pipex infile "ls -l" "grep pipex" outfile`

Ce qui exécute les commandes `ls -l` et `grep pipex` en utilisant un pipeline, en utilisant le contenu du fichier infile comme entrée et en écrivant la sortie dans le fichier outfile.

## Bonus

La partie bonus du projet consiste à ajouter la prise en charge de plusieurs commandes.

Pour utiliser cette fonctionnalité, vous pouvez ajouter autant de commandes que vous le souhaitez en les séparant par des espaces. Par exemple :

`./pipex infile "ls -l" "grep pipex" "cut -c1-5" outfile`

Ce qui exécute les commandes `ls -l`, `grep pipex` et `cut -c1-5 en utilisant deux pipes, en utilisant le contenu du fichier infile comme entrée et en écrivant la sortie dans le fichier outfile.
