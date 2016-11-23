/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_cos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:00:53 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 15:14:21 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect.h"

double		vect_cos(t_vect a, t_vect b)
{
	double ret;

	a = vect_unit(a);
	b = vect_unit(b);
	ret = a.x * b.x + a.y * b.y + a.z * b.z;
	return (ret);
}
