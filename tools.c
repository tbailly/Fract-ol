/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:31:28 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/12 17:33:54 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_clean(void)
{
	printf("EXIT\n");
	// mlx_destroy_image(params->mlx->mlx, params->mlx->img);
	exit(0);
}
