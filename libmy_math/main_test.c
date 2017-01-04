#include "my_math.h"

int main(void)
{
	double ret[4] = {-1.0, -1.0, -1.0, -1.0};
	t_5pow d;
	d.q4 = 1;
	d.q3 = -10;
	d.q2 = -12;
	d.q1 = 123;
	d.q0 = 123;
	int y = quartic_solver(ret, d);
	printf("%d\n", y);
	for(int i = 0; i < 4; i++)
		printf("%f\n", ret[i]);
	return (0);
}
