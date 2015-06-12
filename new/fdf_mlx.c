/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:43:38 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/12 12:17:39 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_event.h"
#include "keycode.h"

void	key_hook3(t_env *e, int keycode)
{
	if (keycode == KEY_0)
		e->v_map.set = 0;
	else if (keycode == KEY_9)
		e->v_map.set = 1;
	else if (keycode == KEY_1)
		e->v_map.ground = 0;
	else if (keycode == KEY_2)
		e->v_map.ground = 1;
	else if (keycode == KEY_3)
		e->v_map.ground = 2;
	else if (keycode == KEY_4)
		e->v_map.high = 0;
	else if (keycode == KEY_5)
		e->v_map.high = 1;
	else if (keycode == KEY_6)
		e->v_map.high = 2;
	else if (keycode == KEY_7)
		e->v_map.underground = 0;
	else if (keycode == KEY_8)
		e->v_map.underground = 1;
	if (keycode == KEY_M)
		set_color(e, rand() % 3, rand() % 3, rand() % 2);
	else
		set_color(e, e->v_map.high, e->v_map.ground, e->v_map.underground);
}

void	key_hook2(t_env *e, int keycode)
{
	if (keycode == 35)
		e->proj_type = 1;
	else if (keycode == 34)
		e->proj_type = 0;
	else if (keycode == 2)
		e->v_map.img_x = e->v_map.img_x + 35;
	else if (keycode == 0)
		e->v_map.img_x = e->v_map.img_x - 35;
	else if (keycode == 1)
		e->v_map.img_y = e->v_map.img_y + 35;
	else if (keycode == 13)
		e->v_map.img_y = e->v_map.img_y - 35;
	else
		key_hook3(e, keycode);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE)
	{
		ft_double_tab_del((void**)e->mapping);
		mlx_destroy_image(e->mlx, e->img->ptr);
		mlx_destroy_window(e->mlx, e->win);
		ft_wait_exit(0);
	}
	if (keycode == NUM_PAD_PLUS || keycode == KEY_PLUS)
		e->v_map.ecart += 1;
	else if (keycode == NUM_PAD_MOINS || keycode == KEY_MOINS)
		e->v_map.ecart -= 1;
	else if (keycode == 15)
	{
		e->v_map.ecart = -42;
		e->v_map.img_x = -420;
		e->v_map.img_y = -420;
	}
	else
		key_hook2(e, keycode);
	ft_restart(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, 0, 0);
	return (0);
}

t_env	fdf_mlx(t_env *env)
{
	mlx_hook(env->win, KEYPRESS, PRESSMASK, key_hook, env);
	mlx_loop(env->mlx);
	mlx_expose_hook(env->win, expose_hook, env);
	return (*env);
}
