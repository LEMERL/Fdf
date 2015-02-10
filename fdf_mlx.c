#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	printf("key: %d\n", keycode);
	if (keycode == 65307)
	{
		ft_double_tab_del((void**)e->mapping);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 65451 || keycode == 61)
		e->var_map.ecart += 1;
	if (keycode == 65453 || keycode == 45)
		e->var_map.ecart -= 1;
	if (ft_restart(e) == -1)
		exit(0);//ft_error;
	printf("\ne->var_map.ecart : %d\n",e->var_map.ecart);
	printf("\ne->var_map.max_x : %f\n",e->var_map.max_x);
	printf("\ne->var_map.low_x : %f\n",e->var_map.low_x);
	printf("\ne->var_map.max_y : %f\n",e->var_map.max_y);
	printf("\ne->var_map.low_y : %f\n",e->var_map.low_y);
	printf("\ne->var_map.win_x : %d\n",e->var_map.win_x);
	printf("\ne->var_map.win_y : %d\n",e->var_map.win_y);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	(void)x;
	(void)y;
	(void)button;
	return (0);
}

int		expose_hook(t_env *e)
{
	if (ft_restart(e) == -1)
		exit(0);//ft_error;
	return (0);
}

t_env	fdf_mlx(t_env *env)
{
	mlx_key_hook(env->win, key_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (*env);
}
