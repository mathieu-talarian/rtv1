/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:43:14 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/10 10:46:36 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_list(t_list **tmp)
{
	t_list *l;
	l = *tmp;
	while (l)
	{
		printf("%s\n", (char *)l->content);
		printf("size = %zu\n" ,l->content_size);
		l = l->next;
	}
}
