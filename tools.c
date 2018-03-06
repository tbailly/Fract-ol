/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:31:28 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 21:47:57 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_clean(t_params *params_pt, int must_free)
{
	if (must_free)
		mlx_destroy_image(params_pt->mlx_pt->mlx, params_pt->mlx_pt->img);
	exit(0);
}
