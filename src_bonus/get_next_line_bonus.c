/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:43:51 by mbertin           #+#    #+#             */
/*   Updated: 2022/11/07 17:32:45 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*get_next_line(int fd, t_struct *data)
{
	char		*line;
	int			read_value;

	read_value = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (read_value != 0 && !ft_strchr_gnl(data->buffer, '\n'))
	{
		read_value = read(fd, line, BUFFER_SIZE);
		if (read_value == -1)
		{
			free (line);
			return (NULL);
		}
		line[read_value] = '\0';
		data->buffer = ft_strjoin_gnl(data->buffer, line);
	}
	free (line);
	line = clean_line(data->buffer);
	data->buffer = buffer_without_return_line(data->buffer);
	return (line);
}

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

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = (char *)ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	free (s1);
	return (str);
}
