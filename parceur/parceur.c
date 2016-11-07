/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:51:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/07 19:55:24 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_l(t_list **tmp)
{
	t_list *l;
	l = *tmp;
	while (l)
	{
		printf("%s\n", (char *)l->content);
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

void	fill_scene_struct(t_list **l)
{
	t_scene *s;
	t_list *tmp;

	tmp = *l;
	while (tmp)
	{
		if (!ft_strcmp((char *)tmp->content, "name") && tmp->next && !ft_strcmp((char *)tmp->next->content,  "{"))
			go-fill-name!!!!!!!!!
	}
	s = (t_scene *)malloc(sizeof(t_scene));
	s->name = ft_strdup(get_scene_name(l));
	s->cam_origin = get_cam(l);
	print_scene(&s);
}

int		parseur(char *fn)
{
	int		fd;
	char	*line;
	t_list	*l;


	l = NULL;
	line = NULL;
	fd = open (fn, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#')
			fill_list(line, &l);
		ft_strdel(&line);
	}
	close(fd);
	ft_strdel(&line);
	print_l(&l);
	fill_scene_struct(&l);
	return (1);
}
