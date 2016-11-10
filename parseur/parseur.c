/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:53:13 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/10 18:32:36 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_scene_struct(t_list **l)
{
	t_scene *s;
	t_list *tmp;

	tmp = *l;
	s = (t_scene *)malloc(sizeof(t_scene));
	s->name = ft_strdup(get_scene_name(l));
	s->cam_origin = get_cam(l);
	s->win_dim = get_win(l);
	print_scene(&s);
}

int		missing_datas(char *fn)
{
	ft_putstr("rtv1: ");
	ft_putstr(fn);
	ft_putendl(" missing some datas");
	return (0);
}

int		ft_error(char *fn)
{
	ft_putstr("rtv1: ");
	ft_putstr(fn);
	ft_putendl(" wrong type of file or file empty");
	return (0);
}

int		parseur(char *fn)
{
	int		fd;
	char	*line;
	t_list	*l;


	l = NULL;
	line = NULL;
	fd = open (fn, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '#')
			fill_list(line, &l);
		ft_strdel(&line);
	}
	if (!l)
		return (ft_error(fn));
	close(fd);
	if (!test_doc(&l))
		return (missing_datas(fn));
	fill_scene_struct(&l);
	return (1);
}
