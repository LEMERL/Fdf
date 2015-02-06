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

	(void)e;
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
