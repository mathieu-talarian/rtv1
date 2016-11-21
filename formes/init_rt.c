/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:28:51 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/21 18:48:58 by mmoullec         ###   ########.fr       */
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
	e->m = mlx_init();
	e->s = fill_hard_scene();
	print_scene(&e->s);
	e->w = mlx_new_window(e->m, WH, WW, WNA);
	mlx_loop_hook(e->m, start_rt, e);
	mlx_hook(e->w, 2, 1L << 0, key_press, e);
	mlx_loop(e->m);
}
