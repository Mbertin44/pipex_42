/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:58:10 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/03 16:35:57 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/wait.h>

# define TRUE 1
# define FALSE 0

typedef struct s_struct
{
	char			**argv;
	int				argc;
	char			**env;
	char			**split_path;
	char			**path_name;
	char			*good_path;
	int				find_good_path;
	int				cmd_count;
	int				status;
	int				*res_wait;
	int				**pipe;
	int				fd_in;
	int				fd_out;
	int				fork_count;
	int				pid;
	int				heredoc_delimiter;
	struct s_cmd	*cmd;
}	t_struct;

typedef struct s_cmd
{
	char			**env;
	char			**split_cmd;
	char			*full_cmd;
	struct s_cmd	*next;
}	t_cmd;

void		check_path(t_struct *data, int j);
int			size_of_array(char **array);
void		find_and_split_path(t_struct *data);
void		path_with_slash(t_struct *data);
void		init_struct(t_struct *data, int argc, char **argv, char **env);
void		calloc_struct(t_struct **data);
void		piping(t_struct *data);
void		fork_and_execute(t_struct *data);
void		check_fd(t_struct *data, char **argv, char *which_fd);
void		check_redirection(t_struct *data);
void		redirection(int input, int output);
void		close_pipe(t_struct *data);
void		explore_and_free(t_struct *data);
void		free_double_array_char(char **array);
void		free_double_array_int(int **array, t_struct *data);
void		good_path_is_false(t_struct *data);
void		error_and_exit(void);
void		check_access(t_struct *data, int j);
void		wait_all(t_struct *data);
void		heredoc(t_struct *data);

#endif