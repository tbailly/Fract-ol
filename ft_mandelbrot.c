/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:34:31 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 21:54:38 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double x, double y, t_params params)
{
	double	res;
	double	tmp;
	int		iter;

	iter = 0;
	res = x * x + y * y;
	params.imaginary = y;
	params.real = x;
	while (res < 4 && iter < params.max_iter)
	{
		tmp = x * x - y * y;
		y = 2 * x * y + params.imaginary;
		x = tmp + params.real;
		iter++;
		res = x * x + y * y;
	}
	return (iter);
}
