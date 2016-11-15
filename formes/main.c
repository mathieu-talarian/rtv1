/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:31:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/15 20:29:32 by mmoullec         ###   ########.fr       */
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
	tmp->rgb.r = 200;
	tmp->rgb.g = 200;
	tmp->rgb.b = 200;
	return (tmp);
}

void	add_new_obj(t_list **tmp)
{
	ft_lstadd_s(tmp, ft_lstnew(fill_hard_sphere(), sizeof(t_sphere)));
}

void	fill_hard_scene(t_scene **s)
{
	
	(*s)->name = ft_strdup("test");
	(*s)->cam_origin.x = 200.0;
	(*s)->cam_origin.y = 0.0;
	(*s)->cam_origin.z = 0.0;
	(*s)->win_dim.h = 1080;
	(*s)->win_dim.w = 800;
	(*s)->obj = NULL;
}

void	print_scene(t_scene **s)
{
	printf("SCENE\n\n");

	printf("name = %s\n", (*s)->name);
	printf("cam = %f - %f - %f\n", (*s)->cam_origin.x, (*s)->cam_origin.y, (*s)->cam_origin.z);
	printf("height = %d - width = %d\n", (*s)->win_dim.h, (*s)->win_dim.w);
	t_sphere *sp;
	sp = (*s)->obj->content;
	printf("name = %s\n", sp->name);
	printf("inter = %f\n", sp->inter);
	printf("%u %u %u\n", sp->rgb.r, sp->rgb.g, sp->rgb.b);

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
	init_mlx(&e);
	add_new_obj(&e->s->obj);
	print_scene(&e->s);
	mlx_loop_hook(e->m, start_rt, e);
	mlx_hook(e->w, 17, 1L << 17, ft_exit, e);
	mlx_loop(e->m);
return (0);
}
