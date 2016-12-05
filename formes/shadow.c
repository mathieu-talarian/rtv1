/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:28:53 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/05 18:17:48 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

double		if_shadow(t_list_n **obj, t_vect vc_lum_cercle, t_vect pt_cercle)
{
	t_list_n *o;
	t_rend		rend;
	t_rend		tmp;

	rend.t = -1;
	rend.r = rgb_0();
	o = *obj;
	while (o)
	{
		tmp = to_draw_sphere(o->content, pt_cercle, vc_lum_cercle);
		if (rend.t == -1)
			rend = tmp;
		else
		{
			if (tmp.t < rend.t)
				rend = tmp;
		}
		o = o->next;
	}
	return (rend.t);
}
