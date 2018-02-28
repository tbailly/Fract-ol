/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:45:39 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/28 18:22:00 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_points(t_pt *start)
{
	t_pt	*point;
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

void	ft_print_map(t_pt *start)
{
	t_pt	*point;
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