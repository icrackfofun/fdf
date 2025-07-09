/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 23:52:15 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/09 22:32:04 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init(t_fdf *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error(&env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FdF");
	if (!env->win)
		ft_return_error(&env);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error(&env);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	env->map = NULL;
}

static void	ft_map_init(t_fdf *env)
{
	env->map = (t_map *)malloc(sizeof(t_map));
	if (!env->map)
		ft_return_error(&env);
	env->map->height = 0;
	env->map->width = 0;
	env->map->array = NULL;
	env->map->z_max = 0;
	env->map->z_min = 0;
}

static void	ft_set_zoom(t_fdf *env, t_map *map)
{
	if (map->width <= 40 && map->height <= 40)
		env->zoom = 20;
	else if (map->width <= 100 && map->height <= 100)
		env->zoom = 10;
	else if (map->width <= 300 && map->height <= 300)
		env->zoom = 4;
	else
		env->zoom = 1;
}

int	main(int argc, char *argv[])
{
	t_fdf	*env;

	if (argc == 2)
	{
		env = (t_fdf *)malloc(sizeof(t_fdf));
		if (!env)
			exit(1);
		ft_init(env);
		ft_map_init(env);
		ft_check_valid(argv[1], env);
		ft_set_zoom(env, env->map);
		ft_hook_controls(env);
		ft_draw(env->map, env);
		mlx_loop(env->mlx);
	}
	else
		exit(1);
}
