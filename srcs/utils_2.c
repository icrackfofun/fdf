/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:08:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/09 17:10:09 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_map_array(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && *line != '\0' && i < map->height)
	{
		map->array[i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			ft_return_error("malloc error", 1);
		ft_fill_table(map->array[i], line, map->width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

int	ft_count_words(char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++;
	}
	return (width);
}

void	ft_skip_lines(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}
