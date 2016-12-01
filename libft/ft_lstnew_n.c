/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:53:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/01 19:05:48 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_n	*ft_lstnew_n(const char *name, const void *content, \
		size_t content_size)
{
	t_list_n *new;

	if (!(new = (t_list_n *)malloc(sizeof(*new))))
		return (NULL);
	else
	{
		if (!(content))
		{
			new->name = NULL;
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			if (!(new->content = malloc(sizeof(content_size))))
				return (NULL);
			new->name = ft_strdup(name);
			new->content = (void *)content;
			new->content_size = content_size;
		}
		new->next = NULL;
	}
	return (new);
}
