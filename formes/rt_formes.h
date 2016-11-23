/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_formes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:00:21 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 19:53:34 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FORMES_H
# define RT_FORMES_H

# include <mlx.h>
# include "../libft/libft.h"
# include "../libvect/vect.h"
# include "../libmlx/my_mlx.h"
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

typedef struct		s_sphere
{
	char			*name;
	double			inter;
	t_xyz			centre;
	t_rgb			rgb;
}					t_sphere;

typedef struct	s_scene
{
	char		*name;
	t_vect		cam_origin;
	t_hw		win_dim;
	t_sphere		*obj;
}				t_scene;

typedef struct	s_e
{
	t_scene		*s;
	t_mlx		*mlx;
}				t_e;


int			start_rt(t_e *e);
void		circle(t_e *e);
void		rec_l(t_list **obj);

t_scene		*fill_hard_scene();
void		print_scene(t_scene **e);
void		mlc(t_e **e);

t_vect		find_vect_dir(t_vect cam_pos);
t_vect		find_up_vect();
t_vect		find_right_vect();
t_vect		find_up_left(t_vect cam_pos, t_vect upvect, t_vect c, t_vect d);

#endif
