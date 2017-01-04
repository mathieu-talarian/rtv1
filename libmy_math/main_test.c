#include "my_math.h"

int main(void)
{
	double ret[4] = {-1.0, -1.0, -1.0, -1.0};
	t_5pow d;
	d.q4 = 1;
	d.q3 = 0;
	d.q2 = -123;
	d.q1 = -12;
	d.q0 = 1000;
	quaric_solver(ret, d);
	for(int i = 0; i < 4; i++)
		printf("%f\n", ret[i]);
	return (0);
}
