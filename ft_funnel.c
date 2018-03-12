/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funnel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:59:49 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/12 15:02:44 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_funnel(double x, double y, t_params *params)
{
	double	res;
	double	tmp;
	int		iter;
	double	fix_x;
	double	fix_y;

	iter = 0;
	res = 2 * x * y;
	fix_x = x;
	fix_y = y;
	while (res < 4 && iter < params->max_iter)
	{
		tmp = 2 * x * y;
		y = x * x - y * y + fix_x;
		x = tmp + fix_y;
		iter++;
		res = 2 * x * y;
	}
	return (iter);
}
