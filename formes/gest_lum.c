/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_lum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:23:11 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/08 20:55:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

t_rgb		get_lambert_term_cercle(t_e *e, t_vect ray, t_rend rend, t_l l)
{
	t_rgb	ret;
	t_vect pt_cerle;
	pt_cerle = vect_s_mul(ray, rend.t);
	pt_cerle = vect_add(pt_cerle, e->s->cam_origin);
	//	pr_vect(pt_cerle, "PT CERCLE");

	t_vect vc_lum_cercle;

	vc_lum_cercle = vect_unit(vect_sub(e->s->lum->pos, pt_cerle));
	//	t = check_if_coll(&e->s->obj, vc_lum_cercle, e->s->cam_origin);


	t_vect vc_cercle_centre = vect_unit(vect_sub(pt_cerle, rend.centre));

	double dot_product;

	dot_product = vect_cos(vc_cercle_centre, vc_lum_cercle);
	if (dot_product >= 0)
	{
		rend.r.r *= dot_product;
		rend.r.g *= dot_product;
		rend.r.b *= dot_product;
	}
	else
		rend.r = rgb_0();
	return (rend.r);
}

t_rgb	get_lambert_term_plane(t_e *e, t_vect ray, t_rend rend)
{
	t_vect pt_plan;

	t_vect norm_plan = vect_create(rend.norm.a, rend.norm.b, rend.norm.c);
	pt_plan = vect_s_mul(ray, rend.t);
	pt_plan = vect_add(pt_plan, e->s->cam_origin);
	pr_vect(pt_plan, " PT PLAN\n");
//	return (rend.r);
	t_vect vc_lum_plan = vect_unit(vect_sub(e->s->lum->pos, pt_plan));

	double dot_product;
	dot_product = vect_cos(vc_lum_plan, vect_unit(norm_plan));
	if (dot_product > 0)
	{
		rend.r.r *= dot_product;
		rend.r.g *= dot_product;
		rend.r.b *= dot_product;
	}
	return (rend.r);
}

t_rgb	get_ambient(t_rend rend, t_rgb Al)
{
	t_rgb ret;
	t_rgb As;

	As.r = 0.1;
	As.b = 0.1;
	As.g = 0.1;
	ret = rgb_add(rgb_mult(rend.r, Al), rgb_mult(As, rend.r));
	return (ret);
}


void	gest_lum(t_e *e, t_vect ray, t_l l, t_rend rend)
{
	t_rgb lambert_term;
	t_rgb Ia;

	//	Ia = get_ambient(rend, e->s->lum->Al);
	if (rend.type == 0)
	{
		//		new_start(e, ray, rend, l);
		lambert_term = get_lambert_term_cercle(e, ray, rend, l);
		put_color_to_pixel(e->mlx, l, lambert_term);
	}
	if (rend.type == 3)
	{
		lambert_term = get_torus_normal(e, e->s->cam_origin, ray, rend);
		put_color_to_pixel(e->mlx, l, lambert_term);
	}
//	else if (rend.type == 1)
//	{
//		lambert_term =  get_lambert_term_plane(e, ray, rend);
//		put_color_to_pixel(e->mlx, l, lambert_term);
//	}
//	put_color_to_pixel(e->mlx, l, lambert_term);
}
