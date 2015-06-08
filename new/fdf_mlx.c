#include "fdf.h"
#include "keycode.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE)
	{
		ft_double_tab_del((void**)e->mapping);
		mlx_destroy_image(e->mlx, e->img->ptr);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == NUM_PAD_PLUS || keycode == KEY_PLUS)
		e->v_map.ecart += 1;
	if (keycode == NUM_PAD_MOINS || keycode == KEY_MOINS)
		e->v_map.ecart -= 1;
	if (keycode == 15)
	{
		e->v_map.ecart = -42;
		e->v_map.img_x = -420;
		e->v_map.img_y = -420;
	}
	key_hook2(e, keycode);
	ft_restart(e);
	return (0);
}

void	key_hook2(t_env *e, int keycode)
{
	if (keycode == 35)
		e->proj_type = 1;
	if (keycode == 34)
		e->proj_type = 0;
	if (keycode == 2)
		e->v_map.img_x = e->v_map.img_x + 20;
	if (keycode == 0)
		e->v_map.img_x = e->v_map.img_x - 20;
	if (keycode == 1)
		e->v_map.img_y = e->v_map.img_y + 20;
	if (keycode == 13)
		e->v_map.img_y = e->v_map.img_y - 20;
}

int		expose_hook(t_env *e)
{
	(void)e;
	ft_putendl_fd("das ", 2);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, 0, 0);
	return (0);
}

t_env	fdf_mlx(t_env *env)
{
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	mlx_expose_hook(env->win, expose_hook, env);
	return (*env);
}
