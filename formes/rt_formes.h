/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_formes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:00:21 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/05 13:19:19 by mmoullec         ###   ########.fr       */
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
	double			rayon;
	t_vect			centre;
	t_rgb			rgb;
}					t_sphere;

typedef struct		s_plan
{
	char			*name;
	t_vect			pt;
	t_vect			norm;
	t_rgb			color;
}					t_plan;


typedef struct		s_lum
{
	int				num;
	t_vect			pos;
	t_rgb			Al;
	struct s_lum	*next;
}					t_lum;

typedef struct	s_scene
{
	char		*name;
	t_vect		cam_origin;
	t_hw		win_dim;
	t_list_n		*obj;
	t_lum			*lum;
}				t_scene;

typedef struct	s_e
{
	t_scene		*s;
	t_mlx		*mlx;
}				t_e;

typedef struct	s_rend
{
	int			type;
	int			imp;
	double		t;
	t_rgb		r;
	t_vect		centre;
	t_vect		norm;
}				t_rend;


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


void	gest_lum(t_e *e, t_vect ray, t_l l, t_rend rend);
t_rend		to_draw_sphere(t_sphere *s, t_vect cam_origin, t_vect r);


#endif
