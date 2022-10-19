/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:58:10 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/19 09:57:22 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_struct
{
	char			**argv;
	char			**split_path;
	char			**path_name;
	char			*good_path;
	struct s_cmd	*cmd;
}	t_struct;

typedef struct s_cmd
{
	char			**env;
	char			*split_cmd;
	char			**full_cmd;
	struct s_cmd	*next;
}	t_cmd;

char	*check_path(t_struct *data);
int		size_of_array(char **array);
void	find_and_split_path(t_struct *data, char **env);

#endif