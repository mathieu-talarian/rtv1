#include "rt_formes.h"


t_rgb get_torus_normal(t_e *e, t_vect cam, t_vect ray, t_rend rend)
{
	t_vect pt;
	pt = vect_s_mul(ray, rend.t);
	pt = vect_add(pt, cam);

	t_vect centerToPoint = vect_sub(pt, rend.centre);
	float centerToPointDotAxis = vect_dot(centerToPoint, rend.axis);
	t_vect direction = vect_s_mul(rend.axis, centerToPointDotAxis);
	direction = vect_sub(centerToPoint, direction);
	direction = vect_unit(direction);
	t_vect normal = vect_s_mul(direction, rend.orad);
	normal = vect_sub(pt, vect_add(rend.centre, normal));
	normal = vect_unit(normal);
	t_vect vc_lum_plan = vect_unit(vect_sub(e->s->lum->pos, pt));

	double dot_product;
	dot_product = vect_cos(vc_lum_plan, normal);
	if (dot_product > 0)
	{
		rend.r.r *= dot_product;
		rend.r.g *= dot_product;
		rend.r.b *= dot_product;
	}
	else
		rend.r = rgb_0();
	return (rend.r);
}
