/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 23:52:15 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/09 16:52:43 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static t_fdf	*ft_init(void)
{
	t_fdf	*env;
	char	*title;

	title = "FdF";
	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ft_return_error("malloc error", 1);
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error("error connecting to graphics server", 1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	if (!env->win)
		ft_return_error("error initializing window", 1);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error("error initializing image", 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	env->map = NULL;
	return (env);
}

static t_map	*ft_map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_return_error("error initializing map", 1);
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

int	main(int argc, char *argv[])
{
	t_fdf	*env;

	if (argc == 2)
	{
		env = ft_init();
		env->map = ft_map_init();
		ft_check_valid(argv[1], env->map);
		ft_set_zoom(env, env->map);
		ft_hook_controls(env);
		ft_draw(env->map, env);
		mlx_loop(env->mlx);
	}
	else
		ft_return_error("Usage: ./fdf <filename>", 0);
}
