#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int		expose_hook(t_env *e, t_fdf **map)
{

	(void)map;
	(void)e;
	//	if (map)
	//		fdf_trace(map, e);
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
