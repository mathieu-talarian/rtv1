/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:04:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/10/19 18:09:15 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_s(t_list **alst, t_list *new)
{
	t_list *l;

	l = *alst;
	if (new)
	{
		if (!l)
			*alst = new;
		else
		{
			while (l->next)
				l = l->next;
			l->next = new;
		}
	}
}
