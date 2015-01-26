#include "libft/includes/get_next_line.h"
#include "fdf.h"

int		main(int argc, const char *argv[])
{
	t_fdf	**s;
	t_env	e;

	s = fdf_mapping(argc, argv);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, MAX_X, MAX_Y, "titre de la fenetre");
	fdf_trace(s, &e);
	fdf_mlx(&e, s);
	ft_double_tab_del((void**)s);
	return (0);
}
