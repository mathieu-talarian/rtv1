/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:55:15 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/10 14:57:15 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		test_if_name(t_list **tmp)
{
	t_list *l;

	l = *tmp;
	while (l && ft_strcmp((char *)l->content, "objects"))
	{
		if (!ft_strcmp((char *)l->content, "objects"))
			return (0);
		if (!ft_strcmp((char *)l->content, "name"))
			return (1);
		l = l->next;
	}
	return (0);
}

int		test_if_camera(t_list **tmp)
{
	t_list *l;

	l = *tmp;
	while (l && ft_strcmp((char *)l->content, "objects"))
	{
		if (!ft_strcmp((char *)l->content, "objects"))
			return (0);
		if (!ft_strcmp((char *)l->content, "camera"))
			return (1);
		l = l->next;
	}
	return (0);
}

int		test_if_render(t_list **tmp)
{
	t_list *l;

	l = *tmp;
	while (l)
	{
		if (!ft_strcmp((char *)l->content, "objects"))
			return (0);
		if (!ft_strcmp((char *)l->content, "render"))
			return (1);
		l = l->next;
	}
	return (0);
}

int		test_if_object(t_list **tmp)
{
	t_list	*l;
	int		i;

	i = 0;
	l = *tmp;
	while(l)
	{
		printf ("%s\n", (char *)l->content);
		if (!ft_strcmp((char *)l->content, "objects"))
			i++;
		l = l->next;
	}
	return (i);
}

int		test_struct(t_list **tmp)
{
	t_list	*l;
	int		i;

	l = *tmp;
	i = 0;
	while (l)
	{
		if (!ft_strcmp((char *)l->content, "{"))
			i++;
		if (!ft_strcmp((char *)l->content, "}"))
			i--;
		l = l->next;
	}
	return (i);
}

int		test_doc(t_list **tmp)
{
	if (test_struct(tmp) > 0 || test_struct(tmp) < 0 || !test_if_name(tmp) || !test_if_camera(tmp) || !test_if_render(tmp) || !test_if_object(tmp))
		return (0);
	return (1);
}
