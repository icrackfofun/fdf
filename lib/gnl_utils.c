/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:08:07 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/01 09:56:28 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*read_line(int fd, char **buffer)
{
	char		*string;
	ssize_t		bytes_read;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	string = NULL;
	bytes_read = ft_strlen(*buffer);
	if ((*buffer)[0] == '\0')
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
	while (!ft_findnl(*buffer) && bytes_read > 0)
	{
		(*buffer)[bytes_read] = '\0';
		ft_buffercpy(&string, *buffer);
		ft_trimbuffer(*buffer);
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
	}
	if (bytes_read <= 0)
		return (ft_valread(&string, bytes_read, *buffer));
	(*buffer)[bytes_read] = '\0';
	ft_buffercpy(&string, *buffer);
	ft_trimbuffer(*buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE + 1);
		if (!buffer[fd])
			return (NULL);
		ft_memset(buffer[fd], 0, BUFFER_SIZE + 1);
	}
	line = read_line(fd, &buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
