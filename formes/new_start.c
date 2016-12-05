/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:35:16 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/05 19:16:08 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

int			to_shadow(t_list_n **obj, t_vect start, t_vect dir, double t)
{
	t_list_n *o;
	o = *obj;
	t_rend tmp;
	tmp.t = -1;
	t_rend tmp2;
	while (o)
	{
		tmp2 = to_draw_sphere(o->content, start, dir);
		if (tmp.t == -1)
			tmp = tmp2;
		else
			{
				if (tmp2.t < tmp.t)
					tmp = tmp2;
			}
		o = o->next;
	}
	if (tmp.t != 0)
		return (1);
	return (0);
}

void		new_start(t_e *e, t_vect ray, t_rend r, t_l l)
{
	t_vect new_start;

	new_start = vect_add(e->s->cam_origin, vect_s_mul(ray, r.t));
	t_vect n = vect_sub(new_start, r.centre);
	double tmp = vect_length(n);
	if (tmp == 0.0)
		return ;
	n = vect_unit(n);
	double material = 0.5;
	t_vect light = e->s->lum->pos;
	t_vect dist = vect_sub(light, new_start);
	
	double t = vect_length(dist);
	t_vect light_ray_start = new_start;
	t_vect light_ray_dir = vect_unit(dist);
	if (to_shadow(&e->s->obj, light_ray_start, light_ray_dir, t))
	{
		t_rgb lambert_term = get_lambert_term_cercle(e, ray, r, l);
	put_color_to_pixel(e->mlx, l, lambert_term);
	}
}
