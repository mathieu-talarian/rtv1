/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:29:37 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/08 16:30:21 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect.h"

t_plane		plane_create(double a, double b, double c, double d)
{
	t_plane p;

	p.a = a;
	p.b = b;
	p.c = c;
	p.d = d;
	return (p);
}
