/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:43:27 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/02 14:56:17 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>

#include <pthread.h>
# include <mlx.h>
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"

typedef struct		s_point
{
	double			x;
	double			y;
	int				iter;
	struct	s_point	*next;
}					t_point;

typedef struct		s_xy
{
	double			x;
	double			y;
	struct	s_xy	*next;
}					t_xy;

typedef struct		s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}					t_mlx;

typedef struct		s_params
{
	double			min_x;
	double			min_y;
	double			step;
	double			real;
	double			imaginary;
	int				max_iter;
	char			*img_str;
	t_mlx			*mlx_pt;
}					t_params;

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

t_point	*ft_create_list(float startx, float starty, float step);

t_point	*ft_compute_pt(t_point *point);
t_point	*ft_compute_iterations(t_point *start);


char	*ft_draw(t_point *start, char *img_str, int width, int height);

void	ft_print_points(t_point *start);
void	ft_print_map(t_point *start);

void	ft_move(int keycode, t_params *params_pt);
void	ft_zoom(int keycode, t_params *params);
void	ft_precision(int keycode, t_params *params_pt);

t_point	*ft_push_back_point(t_point *start, float x, float y);
t_xy	*ft_push_back_xy(t_xy *start, float x, float y);


void	ft_update_julia_parameters(t_params *params_pt, int x, int y);



void			create_fractal_two(t_params params);
t_params		ft_method_two(t_params params);

#endif
