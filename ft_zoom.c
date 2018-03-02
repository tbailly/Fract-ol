/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:34:34 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/02 14:38:32 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(int keycode, t_params *params_pt)
{
	printf("%f \n", params_pt->min_x);
	printf("%f \n", params_pt->min_y);
	printf("%f \n", params_pt->step);
	if (keycode == 91)
	{
		params_pt->min_x += params_pt->step * WIN_WIDTH / 2;
		params_pt->min_y += params_pt->step * WIN_HEIGHT / 2;
		params_pt->step /= 2;
		params_pt->min_x -= params_pt->step * WIN_WIDTH / 2;
		params_pt->min_y -= params_pt->step * WIN_HEIGHT / 2;
	}
	else
	{
		params_pt->min_x -= params_pt->step * WIN_WIDTH / 2;
		params_pt->min_y -= params_pt->step * WIN_HEIGHT / 2;
		params_pt->step *= 2;
	}
	create_fractal_two(*params_pt);
}

void	ft_move(int keycode, t_params *params_pt)
{
	printf("%f \n", params_pt->min_x);
	printf("%f \n", params_pt->min_y);
	printf("%.17g \n", params_pt->step);
	if (keycode == 126)
		params_pt->min_y -= params_pt->step * 100;
	else if (keycode == 124)
		params_pt->min_x += params_pt->step * 100;
	else if (keycode == 125)
		params_pt->min_y += params_pt->step * 100;
	else if (keycode == 123)
		params_pt->min_x -= params_pt->step * 100;
	//create_fractal(*params_pt);
	create_fractal_two(*params_pt);
}

void	ft_precision(int keycode, t_params *params_pt)
{
	printf("%f \n", params_pt->min_x);
	printf("%f \n", params_pt->min_y);
	printf("%.17g \n", params_pt->step);
	if (keycode == 69 && params_pt->max_iter < 100000)
		params_pt->max_iter += 100;
	if (keycode == 78 && params_pt->max_iter > 100)
		params_pt->max_iter -= 100;
	//create_fractal(*params_pt);
	create_fractal_two(*params_pt);
}

void	ft_update_julia_parameters(t_params *params_pt, int x, int y)
{
	params_pt->real = ((float)x / WIN_WIDTH * 2) - 1;
	params_pt->imaginary = ((float)y / WIN_HEIGHT * 2) - 1;
	printf("donc : %f;%f \n", params_pt->real, params_pt->imaginary);
	create_fractal_two(*params_pt);
}