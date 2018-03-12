/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:49:17 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/12 17:34:09 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_move(int keycode, t_thread **all_threads)
{
	if (keycode == 126)
		all_threads[0]->params->min_y -= all_threads[0]->params->step * 100;
	else if (keycode == 124)
		all_threads[0]->params->min_x += all_threads[0]->params->step * 100;
	else if (keycode == 125)
		all_threads[0]->params->min_y += all_threads[0]->params->step * 100;
	else if (keycode == 123)
		all_threads[0]->params->min_x -= all_threads[0]->params->step * 100;
	ft_refresh_fractal(all_threads);
}

static	void	ft_precision(int keycode, t_thread **all_threads)
{
	if (keycode == 69 && all_threads[0]->params->max_iter < 10000)
		all_threads[0]->params->max_iter += 5;
	if (keycode == 78 && all_threads[0]->params->max_iter > 100)
		all_threads[0]->params->max_iter -= 5;
	ft_refresh_fractal(all_threads);
}

static	void	ft_change_fractal(int keycode, t_thread **all_threads)
{
	all_threads[0]->params = ft_init_params(all_threads[0]->params);
	if (keycode == 12)
	{
		all_threads[0]->params->cur_fractal--;
		if (all_threads[0]->params->cur_fractal == -1)
			all_threads[0]->params->cur_fractal = 5;
	}
	else if (keycode == 14)
	{
		all_threads[0]->params->cur_fractal++;
		if (all_threads[0]->params->cur_fractal == 6)
			all_threads[0]->params->cur_fractal = 0;
	}
	ft_refresh_fractal(all_threads);
}

static	void	ft_change_palette(int keycode, t_thread **all_threads)
{
	if (keycode == 0)
	{
		all_threads[0]->params->color_palette--;
		if (all_threads[0]->params->color_palette < 0)
			all_threads[0]->params->color_palette = 4;
	}
	else if (keycode == 2)
	{
		all_threads[0]->params->color_palette++;
		if (all_threads[0]->params->color_palette == 5)
			all_threads[0]->params->color_palette = 0;
	}
	ft_refresh_fractal(all_threads);
}

int				ft_keyboard_events(int keycode, void *args)
{
	t_thread	**all_threads;

	all_threads = (t_thread**)args;
	if (keycode == 53)
		ft_exit_clean();
	if (keycode == 126 || keycode == 124 || keycode == 125 || keycode == 123)
		ft_move(keycode, all_threads);
	if (keycode == 37)
		all_threads[0]->params->julia_lock = (all_threads[0]->params->julia_lock) ? 0 : 1;
	if (keycode == 69 || keycode == 78)
		ft_precision(keycode, all_threads);
	if (keycode == 12 || keycode == 14)
		ft_change_fractal(keycode, all_threads);
	if (keycode == 0 || keycode == 2)
		ft_change_palette(keycode, all_threads);
	return (0);
}
