/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:43:51 by mbertin           #+#    #+#             */
/*   Updated: 2022/07/14 12:52:23 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_line(char *buffer)
{
	size_t	i;
	char	*new_line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	new_line = ft_calloc(sizeof(char), (ft_strlen(buffer) + 1));
	if (!new_line)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		new_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		new_line[i] = buffer[i];
	return (new_line);
}

char	*buffer_without_return_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	while (buffer[i++])
		new_buffer[j++] = buffer[i];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_value;

	read_value = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (read_value != 0 && !ft_strchr_gnl(buffer, '\n'))
	{	
		read_value = read(fd, line, BUFFER_SIZE);
		if (read_value == -1)
		{
			free (line);
			return (NULL);
		}
		line[read_value] = '\0';
		buffer = ft_strjoin_gnl(buffer, line);
	}
	free (line);
	line = clean_line(buffer);
	buffer = buffer_without_return_line(buffer);
	return (line);
}
