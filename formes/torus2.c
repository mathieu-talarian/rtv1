/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:51:27 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/04 19:00:26 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmy_math/my_math.h"
#include "rt_formes.h"

void	fill_dt(t_torus *s, t_dt_torus *to, t_vect c, t_vect r)
{
	double	a;

	a = carre(s->irad);
	to->g = 4 * a * (carre(r.x) + carre(r.y));
	to->h = 8 * a * (c.x * r.x + c.y * r.y);
	to->i = 4 * a * (carre(c.x) + carre(c.y));
	to->j = carre(vect_length(r));
	to->k = 2 * vect_dot(c, r);
	to->l = carre(vect_length(c)) + (carre(s->irad) - carre(s->orad));
}

void	fill_q4(t_5pow *d, t_dt_torus to)
{
	d->q4 = carre(to.j);
	d->q3 = 2 * to.j * to.k;
	d->q2 = (2 * to.j * to.l) + carre(to.k) - carre(to.g);
	d->q1 = (2 * to.k * to.l) - to.h;
	d->q0 = carre(to.l) - to.i;
}

t_rend	to_draw_torus(t_torus *s, t_vect cam_origin, t_vect r)
{
	t_dt_torus	to;
	t_5pow		d;
	double		ret[4] = {-1.0, -1.0, -1.0, -1.0};
	int			y;
	t_rend rend;

	rend.t = 0;
	rend.imp = 0;
	fill_dt(s, &to, cam_origin, r);
	fill_q4(&d, to);
	if (d.q4 != 0)
		y = quartic_solver(ret, d);
	int i = -1;
	while (++i < 4)
	{
		if (ret[i] > 0.0)
		{
			rend.imp = 1;
			rend.t = 1;
			//				if (rend.t == 0)
			//					rend.t = ret[i];
			//				else if (ret[i] < rend.t)
			//					rend.t = ret[i];
		}
	}
//	printf("rend.t = %f\n", rend.t);
	rend.centre = s->center;
	rend.r = s->rgb;
	return (rend);
}
