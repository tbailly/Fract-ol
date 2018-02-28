/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:45:14 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/28 16:16:53 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pt	*ft_push_back(t_pt *start, float x, float y)
{
	t_pt	*tmp;
	t_pt	*new;

	tmp = start;
	while(tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_pt*)malloc(sizeof(t_pt))))
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

t_pt	*ft_create_list(float startx, float starty, float width, float height, float step)
{
	t_pt	*start;
	float i;
	float j;
	float resx;
	float resy;

	start = NULL;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			resx = startx + (step * j);
			resy = starty + (step * i);
			start = ft_push_back(start, resx, resy);
			j++;
		}
		i++;
	}
	/*start = ft_push_back(NULL, -2, 2);


	start = ft_push_back(NULL, -2, 2);
	start = ft_push_back(start, -1.5, 2);
	start = ft_push_back(start, -1, 2);
	start = ft_push_back(start, -0.5, 2);
	start = ft_push_back(start, 0, 2);
	start = ft_push_back(start, 0.5, 2);
	start = ft_push_back(start, 1, 2);
	start = ft_push_back(start, 1.5, 2);
	start = ft_push_back(start, 2, 2);

	start = ft_push_back(start, -2, 1.5);
	start = ft_push_back(start, -1.5, 1.5);
	start = ft_push_back(start, -1, 1.5);
	start = ft_push_back(start, -0.5, 1.5);
	start = ft_push_back(start, 0, 1.5);
	start = ft_push_back(start, 0.5, 1.5);
	start = ft_push_back(start, 1, 1.5);
	start = ft_push_back(start, 1.5, 1.5);
	start = ft_push_back(start, 2, 1.5);

	start = ft_push_back(start, -2, 1);
	start = ft_push_back(start, -1.5, 1);
	start = ft_push_back(start, -1, 1);
	start = ft_push_back(start, -0.5, 1);
	start = ft_push_back(start, 0, 1);
	start = ft_push_back(start, 0.5, 1);
	start = ft_push_back(start, 1, 1);
	start = ft_push_back(start, 1.5, 1);
	start = ft_push_back(start, 2, 1);

	start = ft_push_back(start, -2, 0.5);
	start = ft_push_back(start, -1.5, 0.5);
	start = ft_push_back(start, -1, 0.5);
	start = ft_push_back(start, -0.5, 0.5);
	start = ft_push_back(start, 0, 0.5);
	start = ft_push_back(start, 0.5, 0.5);
	start = ft_push_back(start, 1, 0.5);
	start = ft_push_back(start, 1.5, 0.5);
	start = ft_push_back(start, 2, 0.5);

	start = ft_push_back(start, -2, 0);
	start = ft_push_back(start, -1.5, 0);
	start = ft_push_back(start, -1, 0);
	start = ft_push_back(start, -0.5, 0);
	start = ft_push_back(start, 0, 0);
	start = ft_push_back(start, 0.5, 0);
	start = ft_push_back(start, 1, 0);
	start = ft_push_back(start, 1.5, 0);
	start = ft_push_back(start, 2, 0);

	start = ft_push_back(start, -2, -0.5);
	start = ft_push_back(start, -1.5, -0.5);
	start = ft_push_back(start, -1, -0.5);
	start = ft_push_back(start, -0.5, -0.5);
	start = ft_push_back(start, 0, -0.5);
	start = ft_push_back(start, 0.5, -0.5);
	start = ft_push_back(start, 1, -0.5);
	start = ft_push_back(start, 1.5, -0.5);
	start = ft_push_back(start, 2, -0.5);

	start = ft_push_back(start, -2, -1);
	start = ft_push_back(start, -1.5, -1);
	start = ft_push_back(start, -1, -1);
	start = ft_push_back(start, -0.5, -1);
	start = ft_push_back(start, 0, -1);
	start = ft_push_back(start, 0.5, -1);
	start = ft_push_back(start, 1, -1);
	start = ft_push_back(start, 1.5, -1);
	start = ft_push_back(start, 2, -1);

	start = ft_push_back(start, -2, -1.5);
	start = ft_push_back(start, -1.5, -1.5);
	start = ft_push_back(start, -1, -1.5);
	start = ft_push_back(start, -0.5, -1.5);
	start = ft_push_back(start, 0, -1.5);
	start = ft_push_back(start, 0.5, -1.5);
	start = ft_push_back(start, 1, -1.5);
	start = ft_push_back(start, 1.5, -1.5);
	start = ft_push_back(start, 2, -1.5);

	start = ft_push_back(start, -2, -2);
	start = ft_push_back(start, -1.5, -2);
	start = ft_push_back(start, -1, -2);
	start = ft_push_back(start, -0.5, -2);
	start = ft_push_back(start, 0, -2);
	start = ft_push_back(start, 0.5, -2);
	start = ft_push_back(start, 1, -2);
	start = ft_push_back(start, 1.5, -2);
	start = ft_push_back(start, 2, -2);*/
	return (start);
}