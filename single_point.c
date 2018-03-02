/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:39:43 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/02 14:37:49 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		ft_compute_point(double x, double y, t_params params)
{
	double	res;
	double	tmp;
	t_xy	*start;
	int		iter;

	iter = 0;
	start = NULL;
	res = x * x + y * y;
	while (res < 4 && iter < params.max_iter)
	{
		tmp = x * x - y * y;
        // y = 2 * x * y + 0.1889; // bi
        // x = tmp + -0.7269; // a

        // y = 2 * x * y + 0.745; // bi
        // x = tmp + -0.123; // a

        y = 2 * x * y + params.imaginary; // bi
        x = tmp + params.real; // a

		iter++;
		res = x * x + y * y;
	}
	return (iter);
}

static	void	ft_draw_point(t_params params, int iter, int x, int y)
{
	int pixel_i;

	if (x < WIN_WIDTH && y < WIN_HEIGHT && x > 0 && y > 0)
	{
		pixel_i = (y * WIN_WIDTH * 4) + (x * 4);
		if (iter == params.max_iter)
		{
			params.img_str[pixel_i] = 0; //BLEU
			params.img_str[pixel_i + 1] = 0; //VERT
			params.img_str[pixel_i + 2] = 0; //ROUGE
			params.img_str[pixel_i + 3] = 0; //TEINTE
		}
		else
		{
			params.img_str[pixel_i] = (iter / 100) * 10; //BLEU
			params.img_str[pixel_i + 1] = (iter / 10 % 10) * 10; //VERT
			params.img_str[pixel_i + 2] = (iter % 10) * 10; //ROUGE
			params.img_str[pixel_i + 3] = 0; //TEINTE
		}
	}
}

t_params		ft_method_two(t_params params)
{
	int		i;
	int		j;
	int		iter;
	double	resx;
	double	resy;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			resx = params.min_x + (params.step * j);
			resy = params.min_y + (params.step * i);
			iter = ft_compute_point(resx, resy, params);
			ft_draw_point(params, iter, j, i);
			j++;
		}
		i++;
	}
	return (params);
}