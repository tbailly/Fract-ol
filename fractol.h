/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:43:27 by tbailly-          #+#    #+#             */
/*   Updated: 2018/10/13 21:48:15 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "stdio.h"

#include <mlx.h>
#include <pthread.h>
#include <errno.h>
#include <math.h>
#include "libft/includes/get_next_line.h"
#include "libft/includes/libft.h"

typedef struct s_mlx
{
  void *mlx;
  void *win;
  void *img;
  char *img_str;
} t_mlx;

typedef struct s_params
{
  double min_x;
  double min_y;
  double step;
  double real;
  double imaginary;
  int max_iter;

  char cur_fractal;
  char julia_lock;

  char color_palette;

  t_mlx *mlx;
} t_params;

typedef struct s_thread
{
  int thread_id;
  t_params *params;
} t_thread;

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define MAX_THREADS 4

t_params *ft_check_error(int ac, char **av);
t_params *ft_init_params(t_params *params);
void *ft_refresh_fractal(t_thread **all_threads);

int ft_mouse_move_events(int x, int y, void *args);
int ft_mouse_events(int button, int x, int y, void *args);
int ft_keyboard_events(int keycode, void *args);

int ft_julia(double x, double y, t_params *params);
int ft_mandelbrot(double x, double y, t_params *params);
int ft_burning_ship(double x, double y, t_params *params);
int ft_butterfly(double x, double y, t_params *params);
int ft_funnel(double x, double y, t_params *params);
int ft_mandelbrot_modified(double x, double y, t_params *params);

void ft_draw_bw(t_params *params, int pixel_i, int iter);
void ft_draw_palette_1(t_params *params, int pixel_i, int iter);
void ft_draw_palette_2(t_params *params, int pixel_i, int iter);
void ft_draw_palette_3(t_params *params, int pixel_i, int iter);
void ft_draw_palette_4(t_params *params, int pixel_i, int iter);

void ft_exit_clean(void);
#endif
