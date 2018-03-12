/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:39:43 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/12 16:07:05 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		ft_compute_point(double x, double y, t_params *params)
{
	int	iter;

	if (params->cur_fractal == 0)
		iter = ft_julia(x, y, params);
	if (params->cur_fractal == 1)
		iter = ft_mandelbrot(x, y, params);
	if (params->cur_fractal == 2)
		iter = ft_burning_ship(x, y, params);
	if (params->cur_fractal == 3)
		iter = ft_butterfly(x, y, params);
	if (params->cur_fractal == 4)
		iter = ft_funnel(x, y, params);
	if (params->cur_fractal == 5)
		iter = ft_mandelbrot_modified(x, y, params);
	return (iter);
}

static	void	ft_draw_point(t_params *params, int iter, int x, int y)
{
	int pixel_i;

	pixel_i = (y * WIN_WIDTH * 4) + (x * 4);
	if (iter == params->max_iter)
	{
		params->mlx->img_str[pixel_i] = 0;
		params->mlx->img_str[pixel_i + 1] = 0;
		params->mlx->img_str[pixel_i + 2] = 0;
		params->mlx->img_str[pixel_i + 3] = 0;
	}
	else
	{
		if (params->color_palette == 0)
			ft_draw_bw(params, pixel_i, iter);
		if (params->color_palette == 1)
			ft_draw_palette_1(params, pixel_i, iter);
		if (params->color_palette == 2)
			ft_draw_palette_2(params, pixel_i, iter);
		if (params->color_palette == 3)
			ft_draw_palette_3(params, pixel_i, iter);
		if (params->color_palette == 4)
			ft_draw_palette_4(params, pixel_i, iter);
	}
}

static	void	ft_compute(t_params *params, int i, int j)
{
	int			iter;
	double		resx;
	double		resy;

	resx = params->min_x - (params->step * j);
	resy = params->min_y - (params->step * i);
	iter = ft_compute_point(resx, resy, params);
	ft_draw_point(params, iter, j, i);
}

static	void	*ft_compute_lines(void *arg)
{
	t_thread	*thread;
	int			i;
	int			j;

	thread = (t_thread*)arg;
	i = thread->thread_id;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			ft_compute(thread->params, i, j);
			j++;
		}
		i += MAX_THREADS;
	}
	pthread_exit(NULL);
}

void			*ft_refresh_fractal(t_thread **all_threads)
{
	pthread_t	thread_id[MAX_THREADS];
	int			i;

	i = 0;
	while (i < MAX_THREADS)
	{
		all_threads[i]->thread_id = i;
		if ((pthread_create(&thread_id[i], NULL, ft_compute_lines, all_threads[i])))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < MAX_THREADS)
	{
		if ((pthread_join(thread_id[i], NULL)))
			return (NULL);
		i++;
	}
	mlx_put_image_to_window(all_threads[0]->params->mlx->mlx, all_threads[0]->params->mlx->win,
		all_threads[0]->params->mlx->img, 0, 0);
	return (all_threads);
}
