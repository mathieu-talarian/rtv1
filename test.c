#include "./libvect/vect.h"

typedef struct	s_eq_plan
{
	float		a;
	float		b;
	float		c;
	float		d;
}				t_eq_plan;

t_eq_plan		find_vp_eq(t_vect n, t_vect a)
{
	t_eq_plan pl;

}

int main(void)
{
	t_eq_plan viewplane;
	t_vect cam_pos = vect_create(2, 6, 3);
	t_vect origin = vect_create(0, 0, 0);

	t_vect pt_exemple = vect_create(1, 2, 3);
	t_vect ray_n_exemple = vect_create(-1, 3, 5);

	t_vect ray_cam_or = vect_sub(origin, cam_pos);
	t_vect ray_unit_cam_or = vect_unit(ray_cam_or);
	t_vect pt_plan = vect_add(ray_unit_cam_or,cam_pos);
	pr_vect(pt_plan, "POINT SUR PLAN\n");
	pr_vect(ray_cam_or, "RAY CAM ORIGIN\n");
	pr_vect(ray_unit_cam_or, "RAY CAM ORIGIN UNIT\n");

	viewplane = find_vp_eq(ray_n_exemple, pt_exemple);
	return (0);
}
