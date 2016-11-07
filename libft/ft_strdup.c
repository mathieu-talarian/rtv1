/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 20:03:29 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/20 16:12:30 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	if (!(dest = ft_strnew(ft_strlen(str))))
		return (NULL);
	if (!str)
		return (NULL);
	return (ft_strcpy(dest, str));
}
