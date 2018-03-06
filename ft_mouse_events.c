/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:32:37 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 21:48:36 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_zoom(int button, t_params *params_pt, int x, int y)
{
	if (button == 4)
	{
		params_pt->min_x -= params_pt->step * x;
		params_pt->min_y -= params_pt->step * y;
		params_pt->step /= 1.1;
		params_pt->min_x += params_pt->step * x;
		params_pt->min_y += params_pt->step * y;
		params_pt->max_iter += 2;
	}
	else if (button == 5)
	{
		params_pt->min_x -= params_pt->step * x;
		params_pt->min_y -= params_pt->step * y;
		params_pt->step *= 1.1;
		params_pt->min_x += params_pt->step * x;
		params_pt->min_y += params_pt->step * y;
		params_pt->max_iter -= 2;
	}
	ft_refresh_fractal(*params_pt);
}

static	void	ft_recenter(t_params *params_pt, int x, int y)
{
	params_pt->min_x -= params_pt->step * x;
	params_pt->min_y -= params_pt->step * y;
	params_pt->min_x += params_pt->step * WIN_WIDTH / 2;
	params_pt->min_y += params_pt->step * WIN_HEIGHT / 2;
	ft_refresh_fractal(*params_pt);
}

int				ft_mouse_events(int button, int x, int y, void *args)
{
	t_params	*params_pt;

	params_pt = (t_params*)args;
	if (button == 2)
		ft_recenter(params_pt, x, y);
	if (button == 4 || button == 5)
		ft_zoom(button, params_pt, x, y);
	return (0);
}

int				ft_mouse_move_events(int x, int y, void *args)
{
	t_params	*params_pt;

	params_pt = (t_params*)args;
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT &&
		!params_pt->julia_lock)
	{
		params_pt->real = ((float)x / WIN_WIDTH * 4) - 2;
		params_pt->imaginary = ((float)y / WIN_HEIGHT * 4) - 2;
		ft_refresh_fractal(*params_pt);
	}
	return (0);
}
