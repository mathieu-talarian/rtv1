/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:14:22 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/20 16:27:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

double		carre(double a) { return (a * a); }

void		fill_dt_torus(t_dt_torus *dt, t_torus *s, t_vect e, t_vect d)
{
	dt->g = 4 * carre(s->a) * (carre(e.x) + carre(e.y));
	dt->h = 8 * carre(s->a) * (d.x * e.x + d.y * e.y);
	dt->i = 4 * carre(s->a) * (carre(d.x) + carre(d.y));
	dt->j = carre(vect_length(e));
	dt->k = 2 * (vect_dot(d, e));
	dt->l = carre(vect_length(d)) + (carre(s->a) - carre(s->b));
}

t_rend		t_draw_torus(t_torus *s, t_vect cam_origin, t_vect r)
{
	t_rend rend;
	t_dt_torus dt;
	fill_dt_torus(&dt, s, cam_origin, r);
	double t = resolve4(dt);
	return (rend);
}
