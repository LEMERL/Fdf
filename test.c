/* ************************************************************************** */
/*                                                                            */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 19:24:05 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/15 14:39:15 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw(t_env *e)
{
	t_fdf	a;
	t_fdf	b;
	int		m;

	m = 5;
a.color = 0x000000;
b.color = 0xFF0000;
	while (m < 495)
	{
		a.aff_x = m;
		a.aff_y = 5;
		b.aff_x = m;
		b.aff_y = 495;
		ft_trace_segm(a, b, e);
		m = m + 25;
	}
	m = 10;
a.color = 0x000000;
b.color = 0x00FF00;
	while (m < 495)
	{
		a.aff_x = m;
		a.aff_y = 5;
		b.aff_x = m;
		b.aff_y = 495;
		ft_trace_segm(a, b, e);
		m = m + 25;
	}
	m = 15;
a.color = 0x000000;
b.color = 0x0000FF;
	while (m < 495)
	{
		a.aff_x = m;
		a.aff_y = 5;
		b.aff_x = m;
		b.aff_y = 495;
		ft_trace_segm(a, b, e);
		m = m + 25;
	}
	m = 20;
a.color = 0x000000;
b.color = 0xFFFF00;
	while (m < 495)
	{
		a.aff_x = m;
		a.aff_y = 5;
		b.aff_x = m;
		b.aff_y = 495;
		ft_trace_segm(a, b, e);
		m = m + 25;
	}
	m = 25;
a.color = 0x000000;
b.color = 0xFF00FF;
	while (m < 495)
	{
		a.aff_x = m;
		a.aff_y = 5;
		b.aff_x = m;
		b.aff_y = 495;
		ft_trace_segm(a, b, e);
		m = m + 25;
	}
/*
	m = 5;
a.color = 0x000000;
b.color = 0x0000FF;
	while (m < 495)
	{
		a.aff_x = m;
		a.aff_y = 495;
		b.aff_x = 250;
		b.aff_y = 250;
		ft_trace_segm(a, b, e);
		m = m + 49;
	}
	m = 5;
a.color = 0x000000;
b.color = 0x00FF00;
	while (m < 495)
	{
		a.aff_x = 495;
		a.aff_y = m;
		b.aff_x = 250;
		b.aff_y = 250;
		ft_trace_segm(a, b, e);
		m = m + 49;
	}
	m = 5;
a.color = 0x000000;
b.color = 0xFF0000;
	while (m < 495)
	{
		a.aff_x = m;
		a.aff_y = 5;
		b.aff_x = 250;
		b.aff_y = 250;
		ft_trace_segm(a, b, e);
		m = m + 49;
	}
	m = 5;
a.color = 0x000000;
b.color = 0xFFFFFF;
	while (m < 495)
	{
		a.aff_x = 5;
		a.aff_y = m;
		b.aff_x = 250;
		b.aff_y = 250;
		ft_trace_segm(a, b, e);
		m = m + 49;
	}*/
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	(void)e;
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int	expose_hook(t_env *e, t_fdf ***map)
{
	(void)map;
	draw(e);
	return (0);
}

int	main(void)
{
	t_env	e;
//	t_fdf	***map;

//	map = ft_get_fdf(/**/);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, MAX_X, MAX_Y, "first_test");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
