/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_modified.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:35:26 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/12 15:03:12 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot_modified(double x, double y, t_params *params)
{
	double	res;
	double	tmp;
	int		iter;
	double	fix_x;
	double	fix_y;

	iter = 0;
	res = x * x + y * y;
	fix_x = x;
	fix_y = y;
	while (res < 4 && iter < params->max_iter)
	{
		tmp = x * x - y * y;
		y = 2 * x * y + fix_x;
		x = tmp + fix_y;
		iter++;
		res = x * x + y * y;
	}
	return (iter);
}
