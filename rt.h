/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:51:34 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/07 19:55:27 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct		s_pars
{
	char			s;
	struct	s_pars	*next;
}					t_pars;

typedef struct	s_xy
{
	double		x;
	double		y;
}				t_xy;

typedef struct	s_xyz
{
	double		x;
	double		y;
	double		z;
}				t_xyz;

typedef struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct		s_obj
{
	char			*name;
	t_rgb			rgb;
	struct s_obj	*next;
}					t_obj;

typedef struct	s_scene
{
	char		*name;
	t_xyz		cam_origin;
	t_xy		win_dim;
	t_obj		*obj;
}				t_scene;

typedef struct	s_e
{
	void		*m;
	void		*w;
	void		*i;
	int			sl;
	int			bpp;
	char		*d_a;
}				t_e;

void	continue_pars(char *str);
void	fill_list(char *line, t_list **l);
void	tab_clr(char ***tab);

int		parseur(char *fn);

char	*get_scene_name(t_list **l);
t_xyz	get_cam(t_list **l);

void	print_scene(t_scene **s);
#endif
