#include "my_math.h"

int quartic_solver(double *ret, t_5pow d)
{
	t_5pow r;
	int nr12;
	int nr34;
	t_4pow a;
	t_4pow au;

	a.q3 = d.q3 / d.q4;
	a.q2 = d.q2 / d.q4;
	a.q1 = d.q1 / d.q4;
	a.q0 = d.q0 / d.q4;

	au.q3 = 1.0;
	au.q2 = -a.q2;
	au.q1 = (a.q1 * a.q3 - 4.0 * a.q0);
	au.q0 = 4.0 * a.q0 * a.q2 - carre(a.q1) - a.q0 * carre(a.q3);

	t_4pow x;
	int nr;

	cubic_equation(au, &x, &nr);

	double u1;
	if (nr == 1)
	{
		u1 = x.q1;
	}
	else
	{
		u1 = (x.q1 > x.q3) ? x.q1 : x.q3;
	}

	double R2 = 0.25 * carre(a.q3) + u1 - a.q2;
	double R = (R2 > 0.0) ? sqrt(R2) : 0.0;

	double D2, E2;
	if (R != 0.0)
	{
		double f1 = 0.75 * carre(a.q3) - R2 - 2.0 * a.q2;
		double f2 = 0.25 * (4.0 * a.q3 * a.q2 - 8.0 * a.q1 - cube(a.q3)) / R;
		D2 = f1 + f2;
		E2 = f1 - f2;
	}
	else {
		double f1 = 0.75*a.q3*a.q3 - 2.0*a.q2;
		double f2 = 2.0 * sqrt(u1*u1 - 4.0*a.q0);
		D2 = f1 + f2;
		E2 = f1 - f2;
	}

	if (D2 >= 0.0) {
		double D = sqrt(D2);
		r.q1 = -0.25*a.q3 + 0.5*R - 0.5*D;
		r.q2 = -0.25*a.q3 + 0.5*R + 0.5*D;
		nr12 = 2;
	}
	else {
		r.q1 = r.q2 = -0.25*a.q3 + 0.5*R;
		nr12 = 0;
	}

	if (E2 >= 0.0) {
		double E = sqrt(E2);
		r.q3 = -0.25*a.q3 - 0.5*R - 0.5*E;
		r.q4 = -0.25*a.q3 - 0.5*R + 0.5*E;
		nr34 = 2;
	}
	else {
		r.q3 = r.q4 = -0.25*a.q3 - 0.5*R;
		nr34 = 0;
	}

	int i=0;
	if (nr12 != 0) {
		ret[i++] = r.q1;
		ret[i++] = r.q2;
	}
	if (nr34 != 0) {
		ret[i++] = r.q3;
		ret[i++] = r.q4;
	}
	return nr12 + nr34;
}
