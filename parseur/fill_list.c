/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:19:51 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/10 11:43:27 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_list(char *line, t_list **l)
{
	char **tab;
	tab = NULL;
	char *tmp;
	char *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strtrim(line);
	tab = ft_strsplit(tmp, ' ');
	for (int i = 0; tab[i]; i++)
	{
		tmp2 = ft_strtrim(tab[i]);
		ft_lstadd_s(l, ft_lstnew(tmp2, ft_strlen(tmp2) + 1));
//		printf("%d - %s\n", i, tab[i]);
		ft_strdel(&tmp2);
	}
	ft_strdel(&tmp);
	ft_tab_clr(&tab);
}
