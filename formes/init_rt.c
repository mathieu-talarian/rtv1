/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:28:51 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/01 17:53:43 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

int		key_press(int keycode, t_e *e)
{
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
	print_scene(&e->s);
	e->mlx = glob_init_mlx(WNA, WW, WH);
//	mlx_loop_hook(e->mlx->m, start_rt, e);
	start_rt(e);
	mlx_put_image_to_window(e->mlx->m, e->mlx->w, e->mlx->i, 0, 0);
	mlx_hook(e->mlx->w, 2, 1L << 0, key_press, e);
	mlx_loop(e->mlx->m);
}
