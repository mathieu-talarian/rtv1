/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:49:55 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 14:58:12 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect.h"

t_vect		vect_add(t_vect a, t_vect b)
{
	t_vect res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}