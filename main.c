#include "libft/includes/get_next_line.h"
#include "fdf.h"

int		main(int argc, const char *argv[])
{
	t_env	e;
	int		y;
	int		x;

	e =fdf_strc_ini(e);
	fdf_calcul_proj(e.mapping, &e);
	x = e.var_map.win_x;
	y = e.var_map.win_y;
	e.win = mlx_new_window(e.mlx, x, y "titre de la fenetre");
//	fdf_trace(e.mapping, &e);
	fdf_mlx(&e, s);
	ft_double_tab_del((void**)s);
	return (0);
}

t_env	fdf_strc_ini(t_env e)
{
	e.mlx = mlx_init();
	e.win = NULL;
	e.img = NULL;
	e.mapping = fdf_mapping(argc, argv);
	e.var_proj.proj_type = 1;
	e.var_proj.paral = 75;
	e.var_proj.iso_1 = 75;
	e.var_proj.iso_2 = 75;
	e.var_map.win_x = 1000;
	e.var_map.win_y = 600;
//	e.var_map.img_x = 500;
//	e.var_map.img_x = 500;
	return (e);
}


