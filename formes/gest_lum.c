/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_lum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:23:11 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/25 18:59:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

void	gest_lum(t_e *e, t_vect ray, t_l l, t_rend rend)
{
	t_vect pos_pt;
	t_vect cam_pt;
	t_vect lum = e->s->lum->pos;
//	print_vect(ray);
//	printf("%f\n", rend.t);
	pos_pt = vect_s_mul(ray,rend.t);
//	printf("VECT DE CAM VERS PT\n");
//	print_vect(pos_pt);
	cam_pt = vect_unit(pos_pt);
//	printf("VECT_UNIT DE CAM VERS PT\n");
//	print_vect(cam_pt);
	pos_pt = vect_add(pos_pt, e->s->cam_origin);
//	printf("POINT SUR CERCLE\n");
//	print_vect(pos_pt);

	t_vect lum_pt;
	lum_pt = vect_sub(pos_pt, e->s->lum->pos);
//	printf("LUM_PT\n");
//	print_vect(lum_pt);
	lum_pt = vect_unit(lum_pt);
//	printf("LUM_VECT_UNIT\n");
//	print_vect(lum_pt);

	double dot_product;

	dot_product = cos(vect_cos(lum_pt, cam_pt));
	if (dot_product <= 0)
		put_color_to_pixel(e->mlx, l, rend.r);
	else
	{
		rend.r.r *= dot_product * 2;
		rend.r.g *= dot_product * 2;
		rend.r.b *= dot_product * 2;
		put_color_to_pixel(e->mlx, l, rend.r);
	}
}
