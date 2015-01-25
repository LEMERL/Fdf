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
	fdf_use_tab(map, e);
	return (0);
}

t_env	fdf_mlx(t_env *env, t_fdf **map)
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, MAX_X, MAX_Y, "titre de la fenetre");
	env = &e;
	mlx_key_hook(e.win, key_hook, env);
	mlx_mouse_hook(e.win, mouse_hook, env);
	mlx_expose_hook(e.win, expose_hook(env, map), env);
	mlx_loop(e.mlx);
	return (e);
}
