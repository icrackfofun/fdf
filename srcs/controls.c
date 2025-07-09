/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:16:54 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/09 15:48:42 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_win(void *params)
{
	t_fdf	*env;
	int		x;
	int		y;

	env = (t_fdf *)params;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	y = -1;
	while (++y < env->map->height)
	{
		x = -1;
		while (++x < env->map->width)
			free(env->map->array[y][x]);
		free(env->map->array[y]);
	}
	free(env->map->array);
	free(env->map);
	free(env);
	exit(0);
}

int	ft_key_press(int keycode, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (keycode == ESCAPE)
		ft_close_win(env);
	return (0);
}

void	ft_hook_controls(t_fdf *env)
{
	mlx_key_hook(env->win, ft_key_press, env);
	mlx_hook(env->win, 17, 0, ft_close_win, env);
}
