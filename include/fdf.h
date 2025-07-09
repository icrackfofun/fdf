/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:04:40 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/09 23:23:42 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGHT 1000
# define Z_HEIGHT 1.0
# define X_OFFSET 650
# define Y_OFFSET 250

# ifdef __linux__

static inline void	destroy_display(void *mlx)
{
	mlx_destroy_display(mlx);
}
#  define ESCAPE 65307

# else

static inline void	destroy_display(void *mlx)
{
	(void)mlx;
}
#  define ESCAPE 53

# endif

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}		t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		***array;
	int		z_max;
	int		z_min;
}			t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		zoom;
	int		size_line;
	int		endian;
	int		steep;
	t_map	*map;
}			t_fdf;

void		ft_check_valid(char *filename, t_fdf *env);
void		ft_fill_map_array(int fd, t_fdf *env);
void		ft_fill_table(int **n, char *line, int width, t_fdf *env);
void		ft_free_split(char **arr);
int			ft_count_words(char *line);
void		ft_skip_lines(int fd);
void		ft_draw(t_map *map, t_fdf *env);
void		ft_put_pixel(t_fdf *env, int x, int y, int color);
void		ft_draw_line(t_point s, t_point e, t_fdf *env);
t_point		project(int x, int y, t_fdf *env);
int			ft_min(int a, int b);
int			get_default_color(int z, t_map *map);
void		ft_return_error(t_fdf **env);

//line algorithm utils
float		ft_abs(float n);
int			ft_ipart(float n);
float		ft_fpart(float n);
float		ft_rfpart(float n);

//Controls
void		ft_hook_controls(t_fdf *env);
int			ft_key_press(int keycode, void *params);
int			ft_close_win(void *params);

#endif
