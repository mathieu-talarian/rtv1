/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:33:38 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/07 17:59:11 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_scene(t_scene **s)
{
	printf("SCENE\n\n");
	t_scene *tmp;

	tmp = *s;

	printf("name = %s\n", tmp->name);
	printf("cam = %f - %f - %f\n", tmp->cam_origin.x, tmp->cam_origin.y, tmp->cam_origin.z);
}
