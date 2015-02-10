#include "libft/includes/get_next_line.h"
#include "fdf.h"

int		main(int argc, const char **argv)
{
	t_env	e;

	if (fdf_strc_ini(&e, argc, argv) == NULL)
			return (-1);//ft_error("allocation failled")
	if (ft_restart(&e) == -1)
		return (-1);
	fdf_mlx(&e);
	return (0);
}

int		ft_restart(t_env *e)
{
	static int		x = 0;
	static int		y = 0;

	fdf_calcul_proj(e->mapping, e);
	if (x != e->var_map.win_x || y != e->var_map.win_y)
	{
		x = e->var_map.win_x;
		y = e->var_map.win_y;
		if (e->win != NULL)
			mlx_destroy_window(e->mlx, e->win);
		if ((e->win = mlx_new_window(e->mlx, x, y, "fdf")) == NULL)
			return (-1);//ft_error("allocation failled")
	}
	else
		mlx_clear_window(e->mlx, e->win);
	fdf_trace(e->mapping, e);
	return (1);
}

t_env	*fdf_strc_ini(t_env *e, int argc, const char **argv)
{
	e->mapping = fdf_mapping(argc, argv);
	e->mlx = mlx_init();
	e->win = NULL;
	e->proj_type = 0;
	e->var_color.degradee = 20;
	e->var_map.win_x = 1000;
	e->var_map.win_y = 1000;
	e->var_map.ecart = -42;
	if (e->mlx == NULL || e->mapping == NULL)
		return (NULL);
	return (e);
}
