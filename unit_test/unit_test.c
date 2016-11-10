#include "rt.h"
int		test_if_name(t_list **l);
int		test_if_camera(t_list **l);
int		test_if_render(t_list **l);
int		test_if_object(t_list **l);


int main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_list	*l;


	l = NULL;
	line = NULL;
	fd = open (av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#')
			fill_list(line, &l);
		ft_strdel(&line);
	}
	close(fd);
	ft_strdel(&line);
//	print_list(&l);
	if (test_if_name(&l))
		printf("ok name\n");
	if (test_if_camera(&l))
		printf("ok cam\n");
	if (test_if_render(&l))
		printf("ok render\n");
	printf("%d\n", test_if_object(&l));
	return (1);
}
