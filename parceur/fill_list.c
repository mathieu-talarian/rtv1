/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:19:51 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/07 17:39:37 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_list(char *line, t_list **l)
{
	char **tab;
	tab = NULL;
	char *tmp;

	tmp = NULL;
	tmp = ft_strtrim(line);
	tab = ft_strsplit(tmp, ' ');
	for (int i = 0; tab[i]; i++)
		ft_lstadd_s(l, ft_lstnew(tab[i], ft_strlen(tab[i])));
//		printf("%d - %s\n", i, tab[i]);
	ft_strdel(&tmp);
	tab_clr(&tab);
}
