#ifndef MY_MATH_H
# define MY_MATH_H

# include <math.h>
# include <stdio.h>

typedef struct	s_5pow
{
	double		q4;
	double		q3;
	double		q2;
	double		q1;
	double		q0;
}				t_5pow;

typedef struct	s_4pow
{
	double		q3;
	double		q2;
	double		q1;
	double		q0;
}				t_4pow;

typedef struct	s_3pow
{
	double		q2;
	double		q1;
	double		q0;
}				t_3pow;

typedef struct	s_cub_sol
{
	t_3pow		a;
	double		q;
	double		r;
	double		d;
}				t_cub_sol;

void			cubic_equation(t_4pow c, t_4pow *x, int *nr);
int				quartic_solver(double *ret, t_5pow d);
double			carre(double a);
double			cube(double a);

#endif
