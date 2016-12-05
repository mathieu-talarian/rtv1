/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj_to_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:53:09 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/05 19:38:40 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

t_rend		check_obj_to_draw(t_e *e, t_list_n **obj, t_vect ray)
{
	t_list_n *o;
	t_rend		rend;
	t_rend		tmp;

	rend.t = -1;
	rend.r = rgb_0();
	o = *obj;
	while (o)
	{
		tmp = ret_tmp(o, e, ray);
		if (tmp.imp == 1)
		{
			if (rend.t == -1)
				rend = tmp;
			else
			{
				if (tmp.t < rend.t)
					rend = tmp;
			}
		}
		o = o->next;
	}
	return (rend);
}
