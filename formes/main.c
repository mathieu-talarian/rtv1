/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:31:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/10 18:31:18 by mmoullec         ###   ########.fr       */
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

t_obj	*add_new_obj()
{
	t_obj *obj;
	obj = (t_obj *)malloc(sizeof(t_obj));
	obj->name = ft_strdup("sphere");
	obj->rgb = add_color();
	obj->next = NULL;
	return (obj);
}

void	fill_hard_scene(t_scene **s)
{
	
	(*s)->name = ft_strdup("test");
	(*s)->cam_origin.x = 200.0;
	(*s)->cam_origin.y = 0.0;
	(*s)->cam_origin.z = 0.0;
	(*s)->win_dim.h = 1080;
	(*s)->win_dim.w = 800;
	(*s)->obj = add_new_obj();
}

void	print_scene(t_scene **s)
{
	printf("SCENE\n\n");
	t_scene *tmp;

	tmp = *s;

	printf("name = %s\n", tmp->name);
	printf("cam = %f - %f - %f\n", tmp->cam_origin.x, tmp->cam_origin.y, tmp->cam_origin.z);
	printf("height = %d - width = %d\n", tmp->win_dim.h, tmp->win_dim.w);
}

int		ft_exit(t_e *e)
{
	printf("exit");
	exit(0);
	return (0);
}

void	init_mlx(t_e **e)
{

	(*e)->m = mlx_init();
	(*e)->w = mlx_new_window((*e)->m, WH1, WW1, WNA1);
}

void	mlc(t_e **e)
{
	*e = (t_e *)malloc(sizeof(t_e));
	(*e)->s = NULL;
	(*e)->s = (t_scene *)malloc(sizeof(t_scene));
}

int main(void)
{
	t_e *e;

	e = NULL;
	mlc(&e);
	fill_hard_scene(&e->s);
	print_scene(&e->s);
	init_mlx(&e);
	mlx_loop_hook(e->m, start_rt, e);
	mlx_hook(e->w, 17, 1L << 17, ft_exit, e);
	mlx_loop(e->m);
return (0);
}
