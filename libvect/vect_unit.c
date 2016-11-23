/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:05:14 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 17:02:18 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect.h"

t_vect		vect_unit(t_vect a)
{
	double		length;

	length = vect_length(a);
	if ((int)length != 0)
		return (vect_s_mul(a, 1.0 / length));
	else
		return (a);
}
