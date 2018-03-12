/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:41:48 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/12 17:33:09 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char		*ft_get_image(t_mlx *mlx)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*img_str;

	bpp = 4;
	size_line = WIN_WIDTH;
	endian = 0;
	if (!(mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)))
		ft_exit_clean();
	if (!(img_str = mlx_get_data_addr(mlx->img, &bpp, &size_line, &endian)))
		ft_exit_clean();
	return (img_str);
}

char			ft_which_fractal(char *fractal_name)
{
	if (!fractal_name)
		return (-1);
	if (!ft_strcmp(fractal_name, "julia"))
		return (0);
	if (!ft_strcmp(fractal_name, "mandelbrot"))
		return (1);
	if (!ft_strcmp(fractal_name, "burning_ship"))
		return (2);
	if (!ft_strcmp(fractal_name, "butterfly"))
		return (3);
	if (!ft_strcmp(fractal_name, "funnel"))
		return (4);
	if (!ft_strcmp(fractal_name, "mandelbrot_modified"))
		return (5);
	return (-1);
}

t_params		*ft_check_error(int ac, char **av)
{
	t_params *params;

	if (!(params = (t_params*)malloc(sizeof(t_params))))
		ft_exit_clean();
	params->cur_fractal = ft_which_fractal(av[1]);
	if (ac != 2 || params->cur_fractal == -1)
	{
		ft_putstr("usage: ./fractol fractal_name\nAvailable fractals :\n- julia\
			\n- mandelbrot\n- burning_ship\n- butterfly\n- funnel\
			\n- mandelbrot_modified\n");
		ft_exit_clean();
	}
	if (WIN_WIDTH < 1 || WIN_WIDTH > 1920 ||
		WIN_HEIGHT < 1 || WIN_HEIGHT > 1080)
	{
		ft_putstr("WIN_WIDTH and/or WIN_HEIGHT is incorrect.\
			\nIt should lie between (1;1) and (1920;1080).\n");
		ft_exit_clean();
	}
	if (MAX_THREADS < 1 || MAX_THREADS > 1080)
	{
		ft_putstr("MAX_THREADS is incorrect. It should lie between 1 and 1080.\
			\nNote that making more threads than WIN_HEIGHT is useless.\n");
		ft_exit_clean();
	}
	return (params);
}

t_params		*ft_init_params(t_params *params)
{
	if (WIN_WIDTH > WIN_HEIGHT)
	{
		params->min_y = -2;
		params->step = (params->min_y * 2) / WIN_HEIGHT;
		params->min_x = WIN_WIDTH * params->step / 2;
	}
	else
	{
		params->min_x = -2;
		params->step = (params->min_x * 2) / WIN_WIDTH;
		params->min_y = WIN_HEIGHT * params->step / 2;
	}
	params->real = 0;
	params->imaginary = 0;
	params->max_iter = 50;
	params->julia_lock = 0;
	params->color_palette = 0;
	return (params);
}

t_thread		**ft_create_threads(t_params *params)
{
	t_thread	*thread;
	t_thread	**all_threads;
	int	i;

	i = 0;
	if (!(all_threads = (t_thread**)malloc(sizeof(t_thread*) * MAX_THREADS)))
		ft_exit_clean();
	while (i < MAX_THREADS)
	{
		if (!(thread = (t_thread*)malloc(sizeof(t_thread))))
			ft_exit_clean();
		thread->thread_id = i;
		thread->params = params;
		all_threads[i] = thread;
		i++;
	}
	return(all_threads);
}

int				main(int ac, char **av)
{
	t_mlx		mlx_c;
	t_params	*params;
	t_thread	**all_threads;
	char		*img_str;

	params = ft_check_error(ac, av);
	mlx_c.mlx = mlx_init();
	mlx_c.win = mlx_new_window(mlx_c.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img_str = ft_get_image(&mlx_c);
	params = ft_init_params(params);
	mlx_c.img_str = img_str;
	params->mlx = &mlx_c;
	all_threads = ft_create_threads(params);

	mlx_key_hook(mlx_c.win, ft_keyboard_events, all_threads);
	mlx_hook(mlx_c.win, 4, 0, ft_mouse_events, all_threads);
	mlx_hook(mlx_c.win, 6, 0, ft_mouse_move_events, all_threads);
	
	if (!(ft_refresh_fractal(all_threads)))
		ft_exit_clean();
	mlx_loop(mlx_c.mlx);
	ft_exit_clean();
	return (0);
}
