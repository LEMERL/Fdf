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
	fdf_calcul_proj(e->mapping, e);
	mlx_clear_window(e, e->win);
	fdf_trace(e->mapping, e);
	return (1);
}

t_env	*fdf_strc_ini(t_env *e, int argc, const char **argv)
{
	e->mlx = mlx_init();
	e->win = NULL;
	e->mapping = fdf_mapping(argc, argv);
	e->proj_type = 1;
	e->var_map.win_x = 1000;
	e->var_map.win_y = 600;
	if (e->mlx == NULL || e->mapping == NULL
			|| ((e->win = mlx_new_window(e->mlx, 1000, 600, "fdf")) == NULL))
		return (NULL);
	return (e);
}
