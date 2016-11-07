#include "rt.h"

int		red_button(void *param)
{
	exit(0);
	return (0);
}

int		main(void)
{
	t_e		*e;
	e = (t_e *)malloc(sizeof(t_e));
	
	e->m = mlx_init();
	e->w = mlx_new_window(e->m, 1024, 768, "rt");
	e->i = mlx_new_image(e->m, 1024, 768);
	mlx_hook(e->w, 17, 1L << 17, red_button, e);
	mlx_loop(e->m);
	return (0);
}
