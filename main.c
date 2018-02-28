/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:41:48 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/28 18:21:41 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_pt	*start;

	//start = ft_create_list(-1.004, -1.004, 40, 40, 0.005);
	// start = ft_create_list(-1.004, -1.004, 60, 60, 0.0005);
	//start = ft_create_list(-0.9955, -1, 60, 60, 0.0005);
	//start = ft_create_list(-0.9955, -1, 60, 60, 0.00005);
	//start = ft_create_list(-0.9955, -1, 60, 60, 0.000005);
	start = ft_create_list(-0.9955, -1, 60, 60, 0.000005);
	start = ft_compute_iterations(start);
	//ft_print_points(start);
	ft_print_map(start);
	return (0);
}