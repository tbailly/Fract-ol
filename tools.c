/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:31:28 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/01 14:19:30 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	*ft_push_back_point(t_point *start, float x, float y)
{
	t_point	*tmp;
	t_point	*new;

	tmp = start;
	while(tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->iter = -1;
	new->next = NULL;

	if (tmp)
		tmp->next = new;
	else
		start = new;
	return (start);
}

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

int		*ft_convert_color(unsigned int color)
{
	int	i;
	int	*res;

	i = 0;
	res = (int*)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		res[i] = color % 256;
		color = color / 256;
		i++;
	}
	return (res);
}