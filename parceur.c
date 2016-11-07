/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:51:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/10/26 20:14:27 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_l(t_list **tmp)
{
	t_list *l;
	l = *tmp;
	while (l)
	{
		printf("%s - ", (char *)l->content);
		l = l->next;
	}
}

void	tab_clr(char ***tab)
{
	char **t;
	t = *tab;
	for (int i = 0; t[i]; i++)
		ft_strdel(&t[i]);
	free(t);
	t = NULL;
}

int main(int ac, char **av)
{
	int		fd;
	char	*line;
	char *tmp = NULL;
	char *ret = NULL;
	char *tmp2 = NULL;

	line = NULL;
	if (ac != 2)
		return (0);
	else
	{
		fd = open (av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			if (line[0] != '#')
			{
				if (!ret)
					ret = ft_strdup(ft_strtrim(line));
				else
				{
					tmp = ft_strjoin(ret, " ");
					tmp2 = ft_strjoin(tmp, ft_strtrim(line));
					ft_strdel(&ret);
					ret = ft_strdup(tmp2);
					ft_strdel(&tmp);
					ft_strdel(&tmp2);
				}
				ft_strdel(&line);
			}
		}
		close(fd);
		ft_strdel(&line);
		printf("%s\n", ret);
		continue_pars(ret);
		return (1);
	}
	return (0);
}
