/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:49:17 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 21:52:45 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_move(int keycode, t_params *params_pt)
{
	if (keycode == 126)
		params_pt->min_y -= params_pt->step * 100;
	else if (keycode == 124)
		params_pt->min_x += params_pt->step * 100;
	else if (keycode == 125)
		params_pt->min_y += params_pt->step * 100;
	else if (keycode == 123)
		params_pt->min_x -= params_pt->step * 100;
	ft_refresh_fractal(*params_pt);
}

static	void	ft_precision(int keycode, t_params *params_pt)
{
	if (keycode == 69 && params_pt->max_iter < 10000)
		params_pt->max_iter += 5;
	if (keycode == 78 && params_pt->max_iter > 100)
		params_pt->max_iter -= 5;
	ft_refresh_fractal(*params_pt);
}

static	void	ft_change_fractal(int keycode, t_params *params_pt)
{
	*params_pt = ft_init_params(*params_pt);
	if (keycode == 12)
	{
		params_pt->cur_fractal--;
		if (params_pt->cur_fractal == -1)
			params_pt->cur_fractal = 5;
	}
	else if (keycode == 14)
	{
		params_pt->cur_fractal++;
		if (params_pt->cur_fractal == 6)
			params_pt->cur_fractal = 0;
	}
	ft_refresh_fractal(*params_pt);
}

static	void	ft_change_palette(int keycode, t_params *params_pt)
{
	if (keycode == 0)
	{
		params_pt->color_palette--;
		if (params_pt->color_palette < 0)
			params_pt->color_palette = 4;
	}
	else if (keycode == 2)
	{
		params_pt->color_palette++;
		if (params_pt->color_palette == 5)
			params_pt->color_palette = 0;
	}
	ft_refresh_fractal(*params_pt);
}

int				ft_keyboard_events(int keycode, void *args)
{
	t_params	*params_pt;

	params_pt = (t_params*)args;
	if (keycode == 53)
		ft_exit_clean(params_pt, 1);
	if (keycode == 126 || keycode == 124 || keycode == 125 || keycode == 123)
		ft_move(keycode, params_pt);
	if (keycode == 37)
		params_pt->julia_lock = (params_pt->julia_lock) ? 0 : 1;
	if (keycode == 69 || keycode == 78)
		ft_precision(keycode, params_pt);
	if (keycode == 12 || keycode == 14)
		ft_change_fractal(keycode, params_pt);
	if (keycode == 0 || keycode == 2)
		ft_change_palette(keycode, params_pt);
	return (0);
}
