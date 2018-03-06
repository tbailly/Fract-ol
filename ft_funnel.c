/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funnel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:59:49 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 21:55:00 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_funnel(double x, double y, t_params params)
{
	double	res;
	double	tmp;
	int		iter;

	iter = 0;
	res = 2 * x * y;
	params.imaginary = x;
	params.real = y;
	while (res < 4 && iter < params.max_iter)
	{
		tmp = 2 * x * y;
		y = x * x - y * y + params.imaginary;
		x = tmp + params.real;
		iter++;
		res = 2 * x * y;
	}
	return (iter);
}
