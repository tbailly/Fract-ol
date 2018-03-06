/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:16:18 by tbailly-          #+#    #+#             */
/*   Updated: 2018/03/06 13:30:32 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned	int	ft_abs(int a)
{
	unsigned	int	ret;

	if (a < 0)
		ret = (unsigned int)a * -1;
	else
		ret = (unsigned int)a;
	return (ret);
}
