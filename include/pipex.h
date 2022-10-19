/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:58:10 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/18 15:28:50 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_struct
{
	char		**argv;
	char		**path;
	char		**path_name;
	char		*good_path;
}	t_struct;

char	*check_path(t_struct *var);

#endif