/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:14:22 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/05 21:51:50 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmy_math/my_math.h"
#include "rt_formes.h"

int			check_ret(double *ret)
{
	int i = -1;
	int j = 0;
	float root;
	while (++i < 4)
	{
		root = ret[i];
		if (root > -1)
			return (1);
	}
	return (0);
}

t_rend		to_draw_torus(t_torus *s, t_vect cam_origin, t_vect r)
{

	t_vect axis = vect_unit(s->axis);
	t_vect centerToRayOrigin = vect_sub(cam_origin, s->center);
	const double centerToRayOriginDotDirection = vect_dot(r,
			centerToRayOrigin);
	double	centerToRayOriginDotDirectionSquared = vect_dot(centerToRayOrigin,
			centerToRayOrigin);
	double innerRadiusSquared = s->irad * s->irad;
	double outerRadiusSquared = s->orad * s->orad;

	double	axisDotCenterToRayOrigin = vect_dot(axis, centerToRayOrigin);
	double	axisDotRayDirection = vect_dot(axis, r);
	double	a = 1 - axisDotRayDirection * axisDotRayDirection;
	double	b = (vect_dot(centerToRayOrigin, r) -
			axisDotCenterToRayOrigin * axisDotRayDirection);
	b *= 2;
	double c = centerToRayOriginDotDirectionSquared -
		axisDotCenterToRayOrigin * axisDotCenterToRayOrigin;
	double	d = centerToRayOriginDotDirectionSquared +
		outerRadiusSquared - innerRadiusSquared;

	t_5pow	zz;
	zz.q4 = 1;
	zz.q3 = 4 * centerToRayOriginDotDirection;
	zz.q2 = 2 * d + zz.q3 * zz.q3 * 0.25 - 4 * outerRadiusSquared * a;
	zz.q1 = zz.q3 * d - 4 * outerRadiusSquared * b;
	zz.q0 = d * d - 4 * outerRadiusSquared * c;

	double ret[4] = {-1.0, -1.0, -1.0, -1.0};
	int j = quartic_solver(ret, zz);
	//	printf("%d\n", j);

	t_rend rend;
	rend.t = 0;
	rend.imp = 0;
	int i = -1;
	//	check_ret(ret);
	if (j == 0)
	{
		//		rend.t = 1;
		//		rend.imp = 1;
		//		rend.r = rgb_create(123, 165, 12);
		return (rend);
	}
	if (j == 2)
	{
		if (check_ret(ret))
		{
			rend.t = 1;
			rend.imp = 1;
			rend.r = rgb_create(123, 16, 245);
			return (rend);
		}
	}
	if (j == 4)
	{
		if (check_ret(ret))
		{
			rend.t = 1;
			rend.imp = 1;
			rend.r = rgb_create(12, 165, 45);
			return (rend);
		}
	}
	return (rend);
}
