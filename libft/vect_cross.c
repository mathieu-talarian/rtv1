/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:06:36 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/15 21:09:31 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	vect_cross(t_vector a, t_vector b)
{
	t_vector ret;

	ret.x = (a.y * b.z) - (a.z * b.y);
	ret.y = (a.z * b.x) - (a.x * b.z);
	ret.z = (a.x * b.y) - (a.y * b.x);
	return (ret);
}
