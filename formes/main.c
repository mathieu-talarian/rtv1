/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:31:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/25 18:59:47 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

t_sphere	*fill_hard_sphere()
{
	t_sphere *tmp;
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	tmp->num = 2;
	tmp->name = ft_strdup("sphere2");
	tmp->inter = 2;
	//	printf("1");
	tmp->centre.x = 1;
	tmp->centre.y = 1;
	tmp->centre.z = 0;
	tmp->rgb.r = 124;
	tmp->rgb.g = 20;
	tmp->rgb.b = 34;
	tmp->next = NULL;
	return (tmp);
}

t_sphere	*fill_hard_sphere2()
{
	t_sphere *tmp;
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	tmp->num = 1;
	tmp->name = ft_strdup("sphere");
	tmp->inter = 2;
	//	printf("1");
	tmp->centre.x = -1;
	tmp->centre.y = -1;
	tmp->centre.z = 1;
	tmp->rgb.r = 2;
	tmp->rgb.g = 190;
	tmp->rgb.b = 200;
	tmp->next = NULL;
	return (tmp);
}

t_sphere	*fill_hard_sphere3()
{
	t_sphere *tmp;
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	tmp->num = 1;
	tmp->name = ft_strdup("sphere");
	tmp->inter = 2;
	//	printf("1");
	tmp->centre.x = 1;
	tmp->centre.y = -1;
	tmp->centre.z = 2;
	tmp->rgb.r = 100;
	tmp->rgb.g = 10;
	tmp->rgb.b = 200;
	tmp->next = NULL;
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

t_lum	*fill_hard_lum()
{
	t_lum	*l;
	
	l = (t_lum *)malloc(sizeof(t_lum));
	l->num = 1;
	l->pos.x = -10;
	l->pos.y = -10;
	l->pos.z = -10;
	l->next = NULL;
	return (l);
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
	s->obj->next = fill_hard_sphere2();
	s->obj->next->next = fill_hard_sphere3();
	s->lum = NULL;
	s->lum = fill_hard_lum();
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
	t_sphere *sp2;
	sp2 = (*s)->obj->next;
	printf("name = %s\n", sp2->name);
	printf("inter = %f\n", sp2->inter);
	printf("%f %f %f\n", sp2->rgb.r, sp2->rgb.g, sp2->rgb.b);
}
