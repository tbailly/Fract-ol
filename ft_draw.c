/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:37:49 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/01 10:34:37 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void			ft_draw_pixel(char *img_str, int iter, int x, int y)
{
	int pixel_i;

	if (x < 60 && y < 60 && x > 0 && y > 0)
	{
		pixel_i = (y * WIN_WIDTH * 4) + (x * 4);
		img_str[pixel_i] = iter % 127; //BLEU
		img_str[pixel_i + 1] = iter % 127; //VERT
		img_str[pixel_i + 2] = iter % 127; //ROUGE
		img_str[pixel_i + 3] = 0; //TEINTE
	}
}

char	*ft_draw(t_point *start, char *img_str, int width, int height)
{
	float	i;
	float	j;
	t_point	*tmp;

	i = 0;
	tmp = start;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_draw_pixel(img_str, tmp->iter, j, i);
			tmp = tmp->next;
			j++;
		}
		i++;
	}
	return (img_str);
}