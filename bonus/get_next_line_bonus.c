/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:11:09 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:29:20 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*cleaner(char **remainder, char *buffer)
{
	if (remainder && *remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (NULL);
}

char	*read_file(int fd, char *buffer, char **remainder)
{
	ssize_t	read_bytes;
	char	*tmp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (cleaner(remainder, NULL));
		buffer[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		if (*remainder == NULL)
			*remainder = ft_strdup("");
		if (!*remainder)
			return (cleaner(remainder, NULL));
		tmp = ft_strjoin(*remainder, buffer);
		if (!tmp)
			return (cleaner(remainder, NULL));
		cleaner(remainder, NULL);
		*remainder = tmp;
		if (ft_strchr(*remainder, '\n'))
			break ;
	}
	return (*remainder);
}

char	*extract_line(char **remainder)
{
	char	*line;
	char	*new_pos;
	char	*tmp;

	if (!*remainder || !**remainder)
		return (cleaner(remainder, NULL));
	new_pos = ft_strchr(*remainder, '\n');
	if (new_pos)
	{
		line = ft_substr(*remainder, 0, new_pos - *remainder + 1);
		if (!line)
			return (cleaner(remainder, NULL));
		tmp = ft_strdup(new_pos + 1);
		if (!tmp)
			return (cleaner(remainder, line));
		free(*remainder);
		*remainder = tmp;
	}
	else
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*saver;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (cleaner(&remainder, NULL));
	if (!read_file(fd, buffer, &remainder))
	{
		free(buffer);
		return (NULL);
	}
	if (!remainder)
		return (cleaner(&remainder, NULL));
	free(buffer);
	saver = extract_line(&remainder);
	return (saver);
}
