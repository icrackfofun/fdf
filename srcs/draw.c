/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:12:15 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/09 16:49:56 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project(int x, int y, t_fdf *env)
{
	t_point	point;
	int		z;

	z = env->map->array[y][x][0];
	if (env->map->array[y][x][1] >= 0)
		point.color = env->map->array[y][x][1];
	else
		point.color = get_default_color(z, env->map);
	point.x = (x - y) * 0.866 * env->zoom;
	point.y = (x + y) * 0.5 * env->zoom - (z * env->zoom / Z_HEIGHT);
	point.x += X_OFFSET;
	point.y += Y_OFFSET;
	point.z = z;
	point.reverse = 0;
	return (point);
}

void	ft_draw(t_map *map, t_fdf *env)
{
	int	x;
	int	y;

	ft_memset(env->data_addr, 0, WIDTH * HEIGHT * (env->bpp / 8));
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				ft_draw_line(project(x, y, env), project(x + 1, y, env), env);
			if (y < map->height - 1)
				ft_draw_line(project(x, y, env), project(x, y + 1, env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
