/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:29:00 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/08 18:14:24 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_bw(t_params *params, int pixel_i, int iter)
{
	params->mlx->img_str[pixel_i] = iter * 20;
	params->mlx->img_str[pixel_i + 1] = iter * 20;
	params->mlx->img_str[pixel_i + 2] = iter * 20;
	params->mlx->img_str[pixel_i + 3] = 0;
}

void	ft_draw_palette_1(t_params *params, int pixel_i, int iter)
{
	params->mlx->img_str[pixel_i] = iter * 16;
	params->mlx->img_str[pixel_i + 1] = iter * 4;
	params->mlx->img_str[pixel_i + 2] = iter * 8;
	params->mlx->img_str[pixel_i + 3] = 0;
}

void	ft_draw_palette_2(t_params *params, int pixel_i, int iter)
{
	params->mlx->img_str[pixel_i] = iter * 10;
	params->mlx->img_str[pixel_i + 1] = iter * 5;
	params->mlx->img_str[pixel_i + 2] = iter;
	params->mlx->img_str[pixel_i + 3] = 0;
}

void	ft_draw_palette_3(t_params *params, int pixel_i, int iter)
{
	params->mlx->img_str[pixel_i] = iter * 10;
	params->mlx->img_str[pixel_i + 1] = iter * 20;
	params->mlx->img_str[pixel_i + 2] = iter;
	params->mlx->img_str[pixel_i + 3] = 0;
}

void	ft_draw_palette_4(t_params *params, int pixel_i, int iter)
{
	params->mlx->img_str[pixel_i] = iter * 20;
	params->mlx->img_str[pixel_i + 1] = iter * 10;
	params->mlx->img_str[pixel_i + 2] = iter * 5;
	params->mlx->img_str[pixel_i + 3] = 0;
}
