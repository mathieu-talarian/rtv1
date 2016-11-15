/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_formes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:00:21 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/15 20:31:11 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FORMES_H
# define RT_FORMES_H

# include <mlx.h>
# include "../libft/libft.h"
# define WNA1 (*e)->s->name
# define WH1 (*e)->s->win_dim.h
# define WW1 (*e)->s->win_dim.w

# define WNA e->s->name
# define WH e->s->win_dim.h
# define WW e->s->win_dim.w

typedef struct		s_pars
{
	char			s;
	struct	s_pars	*next;
}					t_pars;

typedef struct		s_hw
{
	int				h;
	int				w;
}					t_hw;

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

typedef struct		s_sphere
{
	char			*name;
	double			inter;
	t_rgb			rgb;
}					t_sphere;

typedef struct	s_scene
{
	char		*name;
	t_xyz		cam_origin;
	t_hw		win_dim;
	t_list		*obj;
}				t_scene;

typedef struct	s_e
{
	void		*m;
	void		*w;
	void		*i;
	int			sl;
	int			bpp;
	char		*d_a;
	t_scene		*s;
}				t_e;


int			start_rt(t_e *e);
void		circle(t_e *e);
void		rec_l(t_list **obj);


#endif
