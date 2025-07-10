/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:10:29 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/10 00:16:02 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_height(char *filename, t_fdf *env)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error(&env);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || *line == '\0')
			break ;
		height++;
		free(line);
	}
	if (line)
		free(line);
	if (close(fd) == -1)
		ft_return_error(&env);
	return (height);
}

static int	ft_get_width(char *filename, t_fdf *env)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error(&env);
	line = get_next_line(fd);
	if (!line || *line == '\0')
		ft_return_error(&env);
	width = ft_count_words(line);
	free(line);
	ft_skip_lines(fd);
	if (close(fd) == -1)
		ft_return_error(&env);
	return (width);
}

void	ft_fill_map_array(int fd, t_fdf *env)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && *line != '\0' && i < env->map->height)
	{
		env->map->array[i] = malloc(sizeof(int *) * env->map->width);
		if (!env->map->array[i])
			ft_return_error(&env);
		ft_fill_table(env->map->array[i], line, env->map->width, env);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

static void	ft_get_z_min_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_check_valid(char *filename, t_fdf *env)
{
	int	fd;

	env->map->width = ft_get_width(filename, env);
	env->map->height = ft_get_height(filename, env);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error(&env);
	env->map->array = malloc(sizeof(int **) * env->map->height);
	if (!env->map->array)
		ft_return_error(&env);
	ft_fill_map_array(fd, env);
	ft_get_z_min_max(env->map);
	if (close(fd) == -1)
		ft_return_error(&env);
}
