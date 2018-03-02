/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:45:14 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/02 11:45:28 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_xy	*ft_check_loop(t_xy *start, float x, float y)
{
	t_xy	*tmp;

	tmp = start;
	while (tmp)
	{
		printf("tmp %f;%f et xy %f;%f \n", tmp->x, tmp->y, x, y);
		if (tmp->x == x && tmp->y == y)
			return (NULL);
		tmp = tmp->next;
	}
	start = ft_push_back_xy(start, x, y);
	return (start);
}

t_point	*ft_compute_pt(t_point *point)
{
	float	res;
	float	x;
	float	y;
	float	tmp;
	t_xy	*start;

	x = point->x;
	y = point->y;
	point->iter = 0;
	start = NULL;
	res = x * x + y * y;
	while (res < 4 && point->iter < MAX_ITER)
	{
		//printf("%i --- %f;%f -> %f \n", point->iter, x, y, res);
		tmp = x;
		x += x * x - y * y;
		y += 2 * tmp * y;

		point->iter++;
		res = x * x + y * y;
	}
	return (point);
}

t_point	*ft_compute_iterations(t_point *start)
{
	t_point	*tmp;
	int		i;

	tmp = start;
	i = 0;
	while (tmp)
	{
		tmp = ft_compute_pt(tmp);
		i++;
		tmp = tmp->next;
	}
	return (start);
}

t_point	*ft_create_list(float startx, float starty, float step)
{
	t_point	*start;
	float i;
	float j;
	float resx;
	float resy;

	start = NULL;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			resx = startx + (step * j);
			resy = starty + (step * i);
			start = ft_push_back_point(start, resx, resy);
			j++;
		}
		i++;
	}
	return (start);
}

void	create_fractal(t_params params)
{
	t_point		*start;

	start = ft_create_list(params.min_x, params.min_y, params.step);	
	start = ft_compute_iterations(start);
	params.img_str = ft_draw(start, params.img_str, WIN_WIDTH, WIN_HEIGHT);

	//ft_print_points(start);
	ft_print_map(start);

	mlx_put_image_to_window(params.mlx_pt->mlx, params.mlx_pt->win, params.mlx_pt->img, 0, 0);
}