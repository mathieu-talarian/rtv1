/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:31:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/01 22:23:21 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

t_sphere	*fill_hard_sphere()
{
	t_sphere *tmp;
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	tmp->name = ft_strdup("sphere");
	tmp->rayon = 2;
	tmp->centre.x = 0;
	tmp->centre.y = 0;
	tmp->centre.z = 0;
	tmp->rgb.r = 124;
	tmp->rgb.g = 20;
	tmp->rgb.b = 34;
	return (tmp);
}

t_sphere	*fill_hard_sphere2()
{
	t_sphere *tmp;
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	//	printf("1");
	tmp->centre.x = 1;
	tmp->centre.y = 1;
	tmp->centre.z = 0;
	tmp->rgb.r = 2;
	tmp->rgb.g = 190;
	tmp->rgb.b = 200;
	return (tmp);
}

t_sphere	*fill_hard_sphere3()
{
	t_sphere *tmp;
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	//	printf("1");
	tmp->centre.x = 2;
	tmp->centre.y = 0;
	tmp->centre.z = 0;
	tmp->rgb.r = 100;
	tmp->rgb.g = 10;
	tmp->rgb.b = 200;
	return (tmp);
}

t_plan		*fill_hard_plan2()
{
	t_plan *p;

	p = (t_plan *)malloc(sizeof(t_plan));
	p->name = ft_strdup("plan");
	p->pt = vect_create(0, 0, -1);
	p->norm = vect_create(1, 4, 4);
	p->color = rgb_create(0, 255, 255);
	return (p);
}

t_plan		*fill_hard_plan()
{
	t_plan *p;

	p = (t_plan *)malloc(sizeof(t_plan));
	p->name = ft_strdup("plan");
	p->pt = vect_create(0, -2, 0);
	p->norm = vect_create(1, 2, -1);
	p->color = rgb_create(200, 120, 130);
	return (p);
}


t_list *fill_objs(void)
{
	t_list *l;
	l = NULL;
	ft_lstadd_s(&l, ft_lstnew(fill_hard_sphere(), sizeof(t_sphere) + 1));
	return (l);
}

t_lum	*fill_hard_lum()
{
	t_lum	*l;
	
	l = (t_lum *)malloc(sizeof(t_lum));
	l->num = 1;
	l->pos.x = 0;
	l->pos.y = 0;
	l->pos.z = -10;
	l->Al.r = 255;
	l->Al.g = 255;
	l->Al.b = 255;
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
	ft_lstadd_n(&s->obj, ft_lstnew_n("sphere", fill_hard_sphere(), sizeof(t_sphere)));
	ft_lstadd_n(&s->obj, ft_lstnew_n("plan", fill_hard_plan(), sizeof(t_plan)));
	ft_lstadd_n(&s->obj, ft_lstnew_n("plan", fill_hard_plan2(), sizeof(t_plan)));
//	s->obj->next = fill_hard_sphere2();
//	s->obj->next->next = fill_hard_sphere3();
	s->lum = NULL;
	s->lum = fill_hard_lum();
	return (s);
}

void	print_sphere(t_sphere *s)
{
	printf("%s\n", s->name);
	printf("%f\n", s->rayon);
	print_vect(s->centre);
}

void	print_plan(t_plan *p)
{
	printf("%s\n", p->name);
	pr_vect(p->pt, "pt");
	pr_vect(p->norm, "norm");
}

void	print_objs(t_list_n **obj)
{
	t_list_n *o;

	int i = 0;
	o = *obj;
	while (o)
	{
		printf("%d\n", i++);
		if (!ft_strcmp(o->name, "sphere"))
			print_sphere(o->content);
		if (!ft_strcmp(o->name, "plan"))
			print_plan(o->content);
		o = o->next;
	}
}

void	print_scene(t_scene **s)
{
	printf("SCENE\n\n");
	printf("name = %s\n", (*s)->name);
	printf("cam = %f - %f - %f\n", (*s)->cam_origin.x, (*s)->cam_origin.y, (*s)->cam_origin.z);
	printf("height = %d - width = %d\n", (*s)->win_dim.h, (*s)->win_dim.w);
	print_objs(&(*s)->obj);
}
