/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:43:27 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/28 17:53:31 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>

# include <mlx.h>
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"

typedef struct		s_pt
{
	float			x;
	float			y;
	int				iter;
	struct	s_pt	*next;
}					t_pt;

typedef struct		s_xy
{
	float			x;
	float			y;
	struct	s_xy	*next;
}					t_xy;

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

t_pt	*ft_create_list(float startx, float starty, float width, float height, float step);

t_pt	*ft_compute_pt(t_pt *point, int max_iter);
t_pt	*ft_compute_iterations(t_pt *start);

void	ft_print_points(t_pt *start);
void	ft_print_map(t_pt *start);

#endif
