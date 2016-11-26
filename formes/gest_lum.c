/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_lum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:23:11 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/26 16:25:15 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

void	gest_lum(t_e *e, t_vect ray, t_l l, t_rend rend)
{
	t_vect pt_cerle;
	pt_cerle = vect_s_mul(ray, rend.t);
	pt_cerle = vect_add(pt_cerle, e->s->cam_origin);
//	pr_vect(pt_cerle, "PT CERCLE");

	t_vect vc_lum_cercle;

	vc_lum_cercle = vect_unit(vect_sub(e->s->lum->pos, pt_cerle));
//	pr_vect(vc_lum_cercle, "VECT DE LA LUM VERS PT");

	t_vect vc_cercle_centre = vect_unit(vect_sub(pt_cerle, rend.centre));
//	pr_vect(vc_cercle_centre, "VECT NORM DU PT DE LA SPHERE VERS LE CENTRE");

	double dot_product;

	dot_product = vect_cos(vc_cercle_centre, vc_lum_cercle);
	if (dot_product <= 0)
	{}//put_color_to_pixel(e->mlx, l, rend.r);
	else
	{
		rend.r.r *= dot_product;
		rend.r.g *= dot_product;
		rend.r.b *= dot_product;
		put_color_to_pixel(e->mlx, l, rend.r);
	}
}
