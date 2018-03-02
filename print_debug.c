/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:45:39 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/01 10:35:02 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_points(t_point *start)
{
	t_point	*point;
	int		i;

	i = 0;
	point = start;
	printf("----- PRINT POINTS ----- \n");
	while (point)
	{
		printf("%i --- %f;%f et i=%i \n", i, point->x, point->y, point->iter);
		i++;
		point = point->next;
	}
	printf("-----  END POINTS  ----- \n");
}

void	ft_print_map(t_point *start)
{
	t_point	*point;
	int		i;
	float tmpy;

	i = 0;
	tmpy = 0;
	point = start;
	printf("----- PRINT MAP ----- \n");
	while (point)
	{
		if (tmpy != point->y)
			printf("\n");
		printf("% 4i", point->iter);
		tmpy = point->y;
		i++;
		point = point->next;
	}
	printf("\n\n-----  END MAP  ----- \n");
}