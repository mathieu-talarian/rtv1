/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:54:41 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/26 14:29:59 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_H
# define VECT_H

# include <math.h>
# include <stdio.h>

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

t_vect			vect_create(double x, double y, double z);
t_vect			vect_add(t_vect a, t_vect b);
t_vect			vect_sub(t_vect a, t_vect b);
t_vect			vect_cross(t_vect a, t_vect b);
t_vect			vect_s_mul(t_vect a, double nb);
t_vect			vect_unit(t_vect a);

double			vect_dot(t_vect a, t_vect b);
double			vect_length(t_vect a);
double			vect_cos(t_vect a, t_vect b);

void			print_vect(t_vect a);
void			pr_vect(t_vect v, char *str);
#endif
