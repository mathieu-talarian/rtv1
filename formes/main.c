/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:31:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/23 19:11:51 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

t_rgb	add_color()
{
	t_rgb r;
	r.r = 233;
	r.g = 200;
	r.b = 12;
	return (r);
}

t_sphere	*fill_hard_sphere()
{
	t_sphere *tmp;
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	tmp->name = ft_strdup("sphere");
	tmp->inter = 100.0;
	//	printf("1");
	tmp->centre.x = 10;
	tmp->centre.y = 10;
	tmp->centre.z = 10;
	tmp->rgb.r = 200;
	tmp->rgb.g = 200;
	tmp->rgb.b = 200;
	return (tmp);
}

t_list *fill_objs(void)
{
	t_list *l;
	l = NULL;
	ft_lstadd_s(&l, ft_lstnew(fill_hard_sphere(), sizeof(t_sphere) + 1));
	return (l);
}

void	add_new_obj(t_list **tmp)
{
	ft_lstadd_s(tmp, ft_lstnew(fill_hard_sphere(), sizeof(t_sphere) + 1));
}

t_scene		*fill_hard_scene(void)
{
	t_scene	*s;
	s = (t_scene *)malloc(sizeof(t_scene));
	s->name = ft_strdup("test");
	s->cam_origin.x = 0.0;
	s->cam_origin.y = 0.0;
	s->cam_origin.z = -10.0;
	s->win_dim.w = 1080;
	s->win_dim.h = 800;
	s->obj = NULL;
	s->obj = fill_hard_sphere();
	return (s);
}

void	print_scene(t_scene **s)
{
	printf("SCENE\n\n");
	printf("name = %s\n", (*s)->name);
	printf("cam = %f - %f - %f\n", (*s)->cam_origin.x, (*s)->cam_origin.y, (*s)->cam_origin.z);
	printf("height = %d - width = %d\n", (*s)->win_dim.h, (*s)->win_dim.w);
	t_sphere *sp;
	sp = (*s)->obj;
	printf("name = %s\n", sp->name);
	printf("inter = %f\n", sp->inter);
	printf("%f %f %f\n", sp->rgb.r, sp->rgb.g, sp->rgb.b);
}

