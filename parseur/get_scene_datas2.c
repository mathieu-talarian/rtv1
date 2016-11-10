/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_datas2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:58:37 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/10 14:17:41 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hw	ret_win(t_list **tmp)
{
	t_hw	hw;
	t_list	*l;
	int		i;

	i = 0;
	l = *tmp;
	while (l && ft_strcmp((char *)l->content, "}"))
	{
		if (i== 0)
			hw.height = ft_atoi((char *)l->content);
		if (i == 1)
			hw.width = ft_atoi((char *)l->content);
		l = l->next;
		i++;
	}
	return (hw);
}


t_hw	get_win(t_list **tmp)
{
	t_list *l;

	l = *tmp;
	while (l)
	{
		if (!ft_strcmp((char *)l->content, "mlx_all_objects") && l->next && l->next->next)
			return (ret_win(&l->next->next));
		l = l->next;
	}
	exit (0);
}
