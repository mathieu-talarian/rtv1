/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:03:30 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 19:53:33 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

void	to_draw(t_mlx *mlx,  t_vect r, t_l l)
{
	t_rgb i;
	i.r = 100;
	i.g = 123;
	i.b = 210;
	double a = r.x * r.x + r.y * r.y + r.z + r.z;
	double b = 2 * (r.x * (-10 - 0) + r.y * (0 - 0) + r.z * (0 - 0));
	double c = ((-10 - 0) * (-10 - 0)) + 0 + 0 - (10 * 10);

	double det = b * b - (4 * a * c);
	if (det < 0)
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
	double xIndent = 0.35/ WW;
	double yIndent = 0.5 / WH;
	printf("\nUPLEFT\n");
	print_vect(upleft);
	t_l l;

	l.x = -1;
	l.y = -1;
	while (++l.y < WH)
	{
		l.x = -1;
		while (++l.x < WW)
		{
			rayon = vect_unit(vect_add(upleft, (vect_sub(vect_s_mul(ri, (xIndent * l.x)), vect_s_mul(up, (yIndent * l.y))))));
			to_draw(e->mlx, rayon, l);
		}
	}
	return (1);
}
