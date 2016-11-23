/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:14:36 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 15:16:22 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect.h"

t_vect		vect_create(double x, double y, double z)
{
	t_vect	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
