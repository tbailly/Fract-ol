/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:41:48 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/02 14:37:03 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static	int		loop_hook(void *params_pt)
// {
// 	static	int a;

// 	if (!a)
// 		a = 0;
// 	a++; // 10 000 per second
// 	if (a % 10000 == 0)
// 	{
// 		ft_update_julia_parameters(params_pt);
// 	}
// 	return (0);
// }
static	int		mouse_hook(int button, int x, int y, void *params_pt)
{
	(void)params_pt;
	printf("button %i x %i y %i \n", button, x, y);
	if (button == 1 && x > 0 && y > 0)
	{
		ft_update_julia_parameters(params_pt, x, y);
	}
	return (0);
}

static	int		keyboard_hook(int keycode, void *params_pt)
{
	printf("keycode : %i \n", keycode);
	if (keycode == 53)
		exit(0);

	if (keycode == 126 || keycode == 124 || keycode == 125 || keycode == 123)
		ft_move(keycode, params_pt);

	if (keycode == 91 || keycode == 84) // 91 8pad 84 2pad
		ft_zoom(keycode, params_pt);

	if (keycode == 69 || keycode == 78) //69 + 78 -
		ft_precision(keycode, params_pt);
	return (0);
}

static char		*ft_get_image(t_mlx *mlx_pt)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*img_str;

	bpp = 4;
	size_line = WIN_WIDTH;
	endian = 0;
	mlx_pt->img = mlx_new_image(mlx_pt->mlx, WIN_WIDTH, WIN_HEIGHT);
	img_str = mlx_get_data_addr(mlx_pt->img, &bpp, &size_line, &endian);
	return (img_str);
}



void		create_fractal_two(t_params params)
{
	params = ft_method_two(params);

	mlx_put_image_to_window(params.mlx_pt->mlx, params.mlx_pt->win, params.mlx_pt->img, 0, 0);
}

t_params		ft_init_display_params()
{
	t_params params;

	if (WIN_WIDTH > WIN_HEIGHT)
	{
		params.min_y = 2;
		params.step = (params.min_y * 2) / WIN_HEIGHT * -1;
		params.min_x = WIN_WIDTH * params.step / 2 * -1;
	}
	else
	{
		params.min_x = 2;
		params.step = (params.min_x * 2) / WIN_WIDTH * -1;
		params.min_y = WIN_HEIGHT * params.step / 2 * -1;
	}
	params.real = 0;
	params.imaginary = 0;
	params.max_iter = 50;
	return (params);
}

int				main(void)
{
	t_mlx		mlx_c;
	t_params	params;
	char		*img_str;

	mlx_c.mlx = mlx_init();
	mlx_c.win = mlx_new_window(mlx_c.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img_str = ft_get_image(&mlx_c);
	mlx_key_hook(mlx_c.win, keyboard_hook, &params);
	mlx_mouse_hook(mlx_c.win, mouse_hook, &params);
	
	params = ft_init_display_params();
	params.img_str = img_str;
	params.mlx_pt = &mlx_c;

	//mlx_loop_hook(mlx_c.mlx, loop_hook, &params);

	create_fractal_two(params);
	
	mlx_loop(mlx_c.mlx);
	return (0);
}