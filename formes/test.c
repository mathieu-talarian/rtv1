/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:40:33 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/06 17:17:22 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvect/vect.h"

t_vect	find_vect_dir(t_vect cam_pos)
{
	t_vect vect_dir = vect_unit(vect_sub(vect_create(0, 0, 0), cam_pos));
//	printf("VECT DIR\n");
//	print_vect(vect_dir);
	return (vect_dir);
}

t_vect	find_up_vect()
{
	t_vect upvect;

	upvect = vect_create(0, 1, 0);
//	printf("\nUPVECT\n");
//	print_vect(upvect);
	return (upvect);
}

t_vect	find_right_vect()
{
	t_vect rightvect;

	rightvect = vect_create(1, 0, 0);
//	printf("\nRIGHTVECT\n");
//	print_vect(rightvect);
	return (rightvect);

}

t_vect	find_up_left(t_vect cam_pos, t_vect upvect, t_vect rightvect, t_vect vec_dir)
{
	t_vect upleft;
	upvect = vect_s_mul(vect_unit(upvect), (0.8 / 2));
	rightvect = vect_s_mul(vect_unit(rightvect), (1.08 / 2));
	t_vect tmp = vect_add(vec_dir, upvect);
	tmp = vect_sub(tmp, rightvect);

	upleft = vect_add(cam_pos, tmp);
//	printf("\nVECT UP LEFT\n");
//	print_vect(upleft);
	return (upleft);
}

/*
t_vect	vp(void)
{
	t_vect vec_dir;
	t_vect upvect;
	t_vect rightvect;
	t_vect up_left;

	vec_dir = find_vect_dir();
	upvect = find_up_vect();
	rightvect = find_right_vect();
	up_left = find_up_left(upvect, rightvect, vec_dir);
	return (0);
}*/
