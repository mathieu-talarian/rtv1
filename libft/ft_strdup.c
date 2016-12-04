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
	int		len;

	dest = NULL;
	len = ft_strlen(str) + 1;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (!str)
		return (NULL);
	return (ft_memcpy(dest, str, len));
}
