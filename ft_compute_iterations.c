/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_iterations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:12:41 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/28 18:16:50 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_xy	*ft_push_back_xy(t_xy *start, float x, float y)
{
	t_xy	*tmp;
	t_xy	*new;

	tmp = start;
	while(tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_xy*)malloc(sizeof(t_xy))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;

	if (tmp)
		tmp->next = new;
	else
		start = new;
	return (start);
}

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

t_pt	*ft_compute_pt(t_pt *point, int max_iter)
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
	while (res < 4 && point->iter < max_iter)
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

t_pt	*ft_compute_iterations(t_pt *start)
{
	t_pt	*tmp;

	tmp = start;
	while (tmp)
	{
		tmp = ft_compute_pt(tmp, 100);
		tmp = tmp->next;
	}
	return (start);
}