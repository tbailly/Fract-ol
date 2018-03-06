/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:39:43 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 22:04:14 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		ft_compute_point(double x, double y, t_params params)
{
	int	iter;

	if (params.cur_fractal == 0)
		iter = ft_julia(x, y, params);
	if (params.cur_fractal == 1)
		iter = ft_mandelbrot(x, y, params);
	if (params.cur_fractal == 2)
		iter = ft_burning_ship(x, y, params);
	if (params.cur_fractal == 3)
		iter = ft_butterfly(x, y, params);
	if (params.cur_fractal == 4)
		iter = ft_funnel(x, y, params);
	if (params.cur_fractal == 5)
		iter = ft_mandelbrot_modified(x, y, params);
	return (iter);
}

static	void	ft_draw_point(t_params params, int iter, int x, int y)
{
	int pixel_i;

	pixel_i = (y * WIN_WIDTH * 4) + (x * 4);
	if (iter == params.max_iter)
	{
		params.img_str[pixel_i] = 0;
		params.img_str[pixel_i + 1] = 0;
		params.img_str[pixel_i + 2] = 0;
		params.img_str[pixel_i + 3] = 0;
	}
	else
	{
		if (params.color_palette == 0)
			ft_draw_bw(params, pixel_i, iter);
		if (params.color_palette == 1)
			ft_draw_palette_1(params, pixel_i, iter);
		if (params.color_palette == 2)
			ft_draw_palette_2(params, pixel_i, iter);
		if (params.color_palette == 3)
			ft_draw_palette_3(params, pixel_i, iter);
		if (params.color_palette == 4)
			ft_draw_palette_4(params, pixel_i, iter);
	}
}

static	void	ft_compute(t_params *params_pt, int i, int j)
{
	int			iter;
	double		resx;
	double		resy;

	resx = params_pt->min_x - (params_pt->step * j);
	resy = params_pt->min_y - (params_pt->step * i);
	iter = ft_compute_point(resx, resy, *params_pt);
	ft_draw_point(*params_pt, iter, j, i);
}

static	void	*ft_compute_lines(void *arg)
{
	int			thread_nb;
	int			i;
	int			j;
	t_params	*params_pt;

	params_pt = (t_params*)arg;
	i = params_pt->cur_thread;
	thread_nb = params_pt->cur_thread;
	(params_pt->cur_thread)++;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			ft_compute(params_pt, i, j);
			j++;
		}
		i += MAX_THREADS;
	}
	if (thread_nb == MAX_THREADS - 1)
		params_pt->cur_thread = 0;
	return (params_pt);
}

t_params		ft_refresh_fractal(t_params params)
{
	pthread_t	thread_id[MAX_THREADS];
	int			i;

	i = 0;
	while (i < MAX_THREADS && i < WIN_HEIGHT)
	{
		pthread_create(&thread_id[i], NULL, ft_compute_lines, &params);
		i++;
	}
	i = 0;
	while (i < MAX_THREADS && i < WIN_HEIGHT)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
	mlx_put_image_to_window(params.mlx_pt->mlx, params.mlx_pt->win,
		params.mlx_pt->img, 0, 0);
	return (params);
}
