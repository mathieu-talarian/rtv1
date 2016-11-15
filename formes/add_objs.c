/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:28:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/15 16:57:04 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

void		rec_l(t_list **l)
{
	t_sphere *sp;
	printf("TEEEST\n");
	if (!(*l))
		dprintf(1, "list n'existe pas");
	else
	{
		sp = (*l)->content;
		printf("%s\n", sp->name);
		printf("%f\n", sp->inter);
	}
}
