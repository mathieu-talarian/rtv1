/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:03:30 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/23 19:11:47 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

void	to_draw(t_mlx *mlx, t_vect r, t_l l)
{
	t_rgb i;
	i.r = 100;
	i.g = 123;
	i.b = 210;

	double a = (r.x * r.x) + (r.y * r.y) + (r.z * r.z);
	double b = 2 * r.z * -10;
	double c = (10 * 10) - 3;
//	printf("%f - %f - %f\n", a, b, c);

//	double t1 = 2 * r.x * -20;
//	printf("%f\n", t1 * t1);
//	double tmp1 = b * b;
//	printf("%f\n", tmp1);
//	double tmp2 = 4 * a * c;
//	printf("%f\n", tmp2);
	double det = (b * b) - (4.0 * a * c);
//	printf("%f\n", det);
	if (det < 0.0)
		return ;
	else
		put_color_to_pixel(mlx, l, i);
}

int		start_rt(t_e *e)
{
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
	printf("\nUPLEFT\n");
	print_vect(upleft);
//	printf("\nUPLEFTUNIT\n");
//	upleft = vect_unit(vect_sub(upleft, e->s->cam_origin));
//	print_vect(upleft);
	t_l l;

	l.x = -1;
	l.y = -1;
//	l.x = 0;
//	l.y = 0;

	while (++l.y < WH)
	{
		l.x = -1;
		while (++l.x < WW)
		{
			rayon = vect_sub(vect_s_mul(ri, (xIndent * l.x)), vect_s_mul(up, (yIndent * l.y)));
			rayon = vect_add(upleft, rayon);
			rayon = vect_sub(rayon, e->s->cam_origin);
			rayon = vect_unit(rayon);
//			printf("RAYON\n%d - %d\n", l.x, l.y);
//			print_vect(rayon);
			to_draw(e->mlx, rayon, l);
		}
	}
	return (1);
}
