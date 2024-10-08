/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_dbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:32:44 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 13:41:18 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_abs_dbl(double a)
{
	double	ret;

	if (a < 0)
		ret = -a;
	else
		ret = a;
	return (ret);
}
