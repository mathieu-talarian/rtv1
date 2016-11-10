/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_datas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:26:45 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/10 13:47:37 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*get_scene_name(t_list **l)
{
	char *ret;
	t_list *tmp;

	ret = NULL;
	tmp = *l;
	while (tmp)
	{
		if (!ft_strcmp((char *)tmp->content, "name"))
			if (tmp->next && !ft_strcmp(tmp->next->content, "{"))
				if (tmp->next->next)
					return (ret = ft_strdup((char *)tmp->next->next->content));
		tmp = tmp->next;
	}
	return (NULL);
}

t_xyz	fill_cam_dt(t_list **l)
{
	t_list *tmp;
	int i;
	t_xyz o;

	tmp = *l;
	i = 0;
	if (!ft_strcmp((char *)tmp->content, "origin") && !ft_strcmp((char *)tmp->next->content, "{") && tmp->next->next)
		tmp = tmp->next->next;
	else
		exit (0);
	while (tmp && ft_strcmp((char *)tmp->content, "}"))
	{
		if (i == 0)
			o.x = ft_atof((char *)tmp->content);
		if (i == 1)
			o.y = ft_atof((char *)tmp->content);
		if (i == 2)
			o.z = ft_atof((char *)tmp->content);
		i++;
		tmp = tmp->next;
	}
	return (o);
}

t_xyz	get_cam(t_list **l)
{
	t_xyz	or;
	t_list	*tmp;

	tmp = *l;
	while (tmp)
	{
		if (!ft_strcmp((char *)tmp->content, "camera"))
			if (tmp->next && !ft_strcmp((char *)tmp->next->content, "{") && tmp->next->next)
				return (fill_cam_dt(&tmp->next->next));
		tmp = tmp->next;
	}
	return (or);
}
