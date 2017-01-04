/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:14:22 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/20 17:59:01 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

t_rend		t_draw_torus(t_torus *s, t_vect cam_origin, t_vect r)
{
	t_vect rayOriginPosition = cam_origin;
	t_vect rayDirection = r;

	t_vect centerToRayOrigin = vect_sub(rayOriginPosition, s->center);
	const float centerToRayOriginDotDirection = vect_dot(rayDirection,
		centerToRayOrigin);
	float	centerToRayOriginDotDirectionSquared = vect_dot(centerToRayOrigin,
		centerToRayOrigin);
	float innerRadiusSquared = s->innerradius * s->innerradius;
	float outerRadiusSquared = s->outerradius * s->outerradius;

	float	axisDotCenterToRayOrigin	= vect_dot(s->axis, centerToRayOrigin);
	float	axisDotRayDirection = vect_dot(s->axis, rayDirection);
	float	a = 1 - axisDotRayDirection * axisDotRayDirection;
	float	b = 2 * vect_dot(centerToRayOrigin, rayDirection) -
	axisDotCenterToRayOrigin * axisDotRayDirection;
	float c = centerToRayOriginDotDirectionSquared -
	axisDotCenterToRayOrigin * axisDotCenterToRayOrigin;
	float	d = centerToRayOriginDotDirectionSquared +
	outerRadiusSquared - innerRadiusSquared;

	t_5pow	zz;
	// Solve quartic equation with coefficients A, B, C, D and E
	zz.q4 = 1;
	zz.q3 = 4 * centerToRayOriginDotDirection;
	zz.q2 = 2 * d + zz.q3 * zz.q3 * 0.25 - 4 * outerRadiusSquared * a;
	zz.q1 = zz.q3 * d - 4 * outerRadiusSquared * b;
	zz.q0 = d * d - 4 * outerRadiusSquared * c;

	// Maximum number of roots is 4
	const int maxRootsCount = 4;
	double roots[maxRootsCount] = {-1.0, -1.0, -1.0, -1.0};
	int i = quartic_solver(roots, zz);
	printf("%d\n", i);
	t_rend oop;
	return (oop);
}
