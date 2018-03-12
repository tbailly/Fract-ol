/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:32:37 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/12 17:41:03 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_zoom(int button, t_thread **all_threads, int x, int y)
{
	if (button == 4)
	{
		all_threads[0]->params->min_x -= all_threads[0]->params->step * x;
		all_threads[0]->params->min_y -= all_threads[0]->params->step * y;
		all_threads[0]->params->step /= 1.5;
		all_threads[0]->params->min_x += all_threads[0]->params->step * x;
		all_threads[0]->params->min_y += all_threads[0]->params->step * y;
		all_threads[0]->params->max_iter += 5;
	}
	else if (button == 5)
	{
		all_threads[0]->params->min_x -= all_threads[0]->params->step * x;
		all_threads[0]->params->min_y -= all_threads[0]->params->step * y;
		all_threads[0]->params->step *= 1.5;
		all_threads[0]->params->min_x += all_threads[0]->params->step * x;
		all_threads[0]->params->min_y += all_threads[0]->params->step * y;
		all_threads[0]->params->max_iter -= 5;
	}
	ft_refresh_fractal(all_threads);
}

static	void	ft_recenter(t_thread **all_threads, int x, int y)
{
	all_threads[0]->params->min_x -= all_threads[0]->params->step * x;
	all_threads[0]->params->min_y -= all_threads[0]->params->step * y;
	all_threads[0]->params->min_x += all_threads[0]->params->step * WIN_WIDTH / 2;
	all_threads[0]->params->min_y += all_threads[0]->params->step * WIN_HEIGHT / 2;
	ft_refresh_fractal(all_threads);
}

int				ft_mouse_events(int button, int x, int y, void *args)
{
	t_thread	**all_threads;

	all_threads = (t_thread**)args;
	if (button == 2)
		ft_recenter(all_threads, x, y);
	if (button == 4 || button == 5)
		ft_zoom(button, all_threads, x, y);
	return (0);
}

int				ft_mouse_move_events(int x, int y, void *args)
{
	t_thread	**all_threads;

	all_threads = (t_thread**)args;
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT &&
		(!all_threads[0]->params->julia_lock && all_threads[0]->params->cur_fractal == 0))
	{
		all_threads[0]->params->real = ((float)x / WIN_WIDTH * 4) - 2;
		all_threads[0]->params->imaginary = ((float)y / WIN_HEIGHT * 4) - 2;
		ft_refresh_fractal(all_threads);
	}
	return (0);
}
