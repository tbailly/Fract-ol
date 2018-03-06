/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:43:27 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 22:03:37 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <mlx.h>
# include <math.h>
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_params
{
	double		min_x;
	double		min_y;
	double		step;
	double		real;
	double		imaginary;
	int			max_iter;
	char		*img_str;

	char		cur_fractal;
	char		julia_lock;

	int			cur_thread;
	char		color_palette;

	t_mlx		*mlx_pt;
}				t_params;

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define MAX_THREADS 1080

t_params		ft_init_params(t_params params);
t_params		ft_refresh_fractal(t_params params);

int				ft_mouse_move_events(int x, int y, void *args);
int				ft_mouse_events(int button, int x, int y, void *args);
int				ft_keyboard_events(int keycode, void *args);

int				ft_julia(double x, double y, t_params params);
int				ft_mandelbrot(double x, double y, t_params params);
int				ft_burning_ship(double x, double y, t_params params);
int				ft_butterfly(double x, double y, t_params params);
int				ft_funnel(double x, double y, t_params params);
int				ft_mandelbrot_modified(double x, double y, t_params params);

void			ft_draw_bw(t_params params, int pixel_i, int iter);
void			ft_draw_palette_1(t_params params, int pixel_i, int iter);
void			ft_draw_palette_2(t_params params, int pixel_i, int iter);
void			ft_draw_palette_3(t_params params, int pixel_i, int iter);
void			ft_draw_palette_4(t_params params, int pixel_i, int iter);

void			ft_exit_clean(t_params *params_pt, int must_free);
#endif
