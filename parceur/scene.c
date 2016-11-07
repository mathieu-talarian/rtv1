/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:27:55 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/07 19:55:25 by mmoullec         ###   ########.fr       */
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
	printf("FILL CAM");
	int i;
	t_xyz o;

	tmp = *l;
	i = 0;
	while (tmp && ft_strcmp((char *)tmp->content, "}"))
	{
		printf("====> %s\n", (char *)tmp->content);
		if (i == 3)
			o.x = ft_atof((char *)tmp->content);
		if (i == 4)
			o.y = ft_atof((char *)tmp->content);
		if (i == 5)
			o.z = ft_atof((char *)tmp->content);
		tmp = tmp->next;
		i++;
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
			if (tmp->next && !ft_strcmp((char *)tmp->next->content, "{"))
			{
				printf("coucou");
				or = fill_cam_dt(&tmp->next);
				return (or);
			}
		tmp = tmp->next;
	}
	return (or);
}
