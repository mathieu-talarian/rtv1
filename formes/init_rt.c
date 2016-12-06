/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:28:51 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/06 17:17:22 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

void	mod(t_lum **l)
{
	(*l)->pos.x++;
	(*l)->pos.y++;
}

void	mod2(t_lum **l)
{
	(*l)->pos.x--;
	(*l)->pos.y--;
}

int		key_press(int keycode, t_e *e)
{
	printf("%d\n", keycode);
	if (keycode == 13)
		e->s->cam_origin.x++;
	if (keycode == 1)
		e->s->cam_origin.x--;
	if (keycode == 0)
		e->s->cam_origin.y--;
	if (keycode == 2)
		e->s->cam_origin.y++;
	if (keycode == 124)
		mod (&e->s->lum);
	if (keycode == 123)
		mod2 (&e->s->lum);
	if (keycode == 53)
		exit (0);
	return (0);
}

int		main(void)
{
	t_e *e;

	int i = 0;
	e = (t_e *)malloc(sizeof(t_e));
	e->s = NULL;
	e->s = fill_hard_scene();
	//print_scene(&e->s);
	e->mlx = glob_init_mlx(WNA, WW, WH);
	mlx_loop_hook(e->mlx->m, start_rt, e);
//	start_rt(e);
	mlx_hook(e->mlx->w, 2, 1L << 0, key_press, e);
	mlx_loop(e->mlx->m);
}
