/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_listing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:41:02 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/01 16:49:17 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

t_obj		*new_obj(char *name, void *content)
{
	t_obj *o;
	o = (t_obj *)malloc(sizeof(t_obj));

	o->name = ft_strdup(name);
	o->content = content;
	return (o);
}

void		fill_list_obj(t_obj **alst, t_obj *new)
{
	
}
