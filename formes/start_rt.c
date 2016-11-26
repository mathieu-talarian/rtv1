/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:03:30 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/26 16:25:16 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

double	find_t_det(double a, double b, double c, double det)
{
	double t1;
	double t2;

	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

double		min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double		carre(double a)
{
	return (a * a);
}

double	return_a(t_vect r)
{
	double a;
	
	a = (r.x * r.x) + (r.y * r.y) + (r.z * r.z);
	return (a);
}

double	return_b(t_vect sp, t_vect r, t_vect cam)
{
	double b;
	b = (r.x * (cam.x - sp.x)) + (r.y * (cam.y - sp.y)) + (r.z * (cam.z - sp.z));
	b *= 2;
	return (b);
}

double	return_c(double inter, t_vect sp, t_vect cam)
{
	double c;
	c = carre(cam.x - sp.x) + carre(cam.y - sp.y) + carre(cam.z -sp.z);
	c -= carre(inter);
	return (c);
}

t_rend	to_draw_sphere(t_sphere *s, t_vect cam_origin, t_vect r, t_l l)
{
	t_rend u;
	double a = return_a(r);
	double b = return_b(s->centre, r, cam_origin);
	double c = return_c(s->inter, s->centre, cam_origin);
	double t;
	double det = (b * b) - (4.0 * a * c);
	if (det < 0.0)
	{
		u.imp = 0;
		return (u);
	}
	else
	{
		u.imp = 1;
		if (det == 0.0)
		{
			u.t = (-b / 2*a);
			u.r = s->rgb;
			u.centre = s->centre;
		}
		else
		{
			u.t = min(((-b + sqrt(det)) / 2 * a), ((-b - sqrt(det)) / 2 * a));
			u.r = s->rgb;
			u.centre = s->centre;
		}
		return (u);
	}
}

void	print_obj(t_sphere **obj)
{
	t_sphere *o;
	o = *obj;
	while (o)
	{
		printf("SPEHERE NUM = %d\n", o->num);
		printf("%s\n", o->name);
		printf("inter = %f\n", o->inter);
		printf("%f %f %f\n", o->rgb.r, o->rgb.g, o->rgb.b);
		o = o->next;
	}
}

t_rgb rgb_0()
{
	t_rgb r;

	r.r = 0;
	r.g = 0;
	r.b = 0;
	return (r);
}

void	all_obj(t_e *e, t_sphere **obj, t_l l, t_vect ray)
{
	t_sphere *o;
	t_rend		rend;
	t_rend		tmp;
	o = *obj;

	rend.t = -1;
	rend.r = rgb_0();
	while(o)
	{
		tmp = to_draw_sphere(o, e->s->cam_origin, ray, l);
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
	gest_lum(e, ray, l, rend);
//	put_color_to_pixel(e->mlx, l, rend.r);
}


int		start_rt(t_e *e)
{
	print_obj(&e->s->obj);
	t_rgb i;
	i.r = 100;
	i.g = 123;
	i.b = 210;
	t_vect vec_dir = find_vect_dir(e->s->cam_origin);
	t_vect up = find_up_vect();
	t_vect ri = find_right_vect();
	t_vect upleft = find_up_left(e->s->cam_origin, up, ri, vec_dir);
	t_vect rayon;
	double xIndent = 1.08 / WW;
	double yIndent = 0.8 / WH;
	t_l l;

	l.x = -1;
	l.y = -1;
	while (++l.y < WH)
	{
		l.x = -1;
		while (++l.x < WW)
		{
			rayon = vect_sub(vect_s_mul(ri, (xIndent * l.x)), vect_s_mul(up, (yIndent * l.y)));
			rayon = vect_add(upleft, rayon);
			rayon = vect_sub(rayon, e->s->cam_origin);
			rayon = vect_unit(rayon);
			all_obj(e, &e->s->obj, l, rayon);
		}
	}
	return (1);
}
