/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 17:45:22 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 17:01:21 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_col(t_trace t, t_env *e)
{
	(void)e;
	(void)t;
	if (t.c1.color >= 0)
		return (t.c1.color);
	if (e->v_map.set != 0)
	{
		if (t.z1 == 0 && t.z2 == 0)
			return (e->var_color.col_ground.color);
		if ((t.z1 > 0 && t.z2 == 0) || (t.z1 == 0 && t.z2 > 0))
			return (e->var_color.col_ground_high.color);
		if (t.z1 > 0 && t.z2 > 0)
			return (e->var_color.col_high.color);
		if (t.z1 < 0 && t.z2 < 0)
			return (e->var_color.col_underground.color);
		if ((t.z1 < 0 && t.z2 == 0) || (t.z1 == 0 && t.z2 < 0))
			return (e->var_color.col_ground_underground.color);
//	if (t.z1 > 0)
//	if (t.z1 < 0)
		return (0x333333);
	}
	else
		return (0xFFFFFe);
}

void		set_color(t_env *e, int high, int ground, int underground)
{
	e->var_color.col_high.color = 0x00FFf0;
	e->var_color.col_ground_high.color = 0x006630;
	if (high == 1)
	{
		e->var_color.col_high.color = 0xA11A1A;
		e->var_color.col_ground_high.color = 0x943C3C;
	}
	else if (high == 2)
	{
		e->var_color.col_high.color = 0xad4c4c;
		e->var_color.col_ground_high.color = 0x843065;
	}
	e->var_color.col_ground.color = 0xFFFF00;
	if (ground == 1)
		e->var_color.col_ground.color = 0xC7C5C5;
	else if (ground == 2)
		e->var_color.col_ground.color = 0xFF00FF;
	e->var_color.col_ground_underground.color = 0xe08e66;
	e->var_color.col_underground.color = 0xf44681;
	if (underground == 1)
	{
		e->var_color.col_ground_underground.color = 0x6ba6ea;
		e->var_color.col_underground.color = 0x1076e9;
	}
}

void		*initialise_stuct(t_env *e, int argc, const char **argv)
{
	e->mapping = fdf_mapping(argc, argv);
	if (e->mapping == NULL)
	{
		ft_putendl("mapping error");
		return (NULL);
	}
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("mlx init error");
		return (NULL);
	}
	set_color(e, 0, 0, 0);
	e->img = NULL;
	e->proj_type = 0;
	e->v_map.win_x = 1000;
	e->v_map.win_y = 1000;
	e->v_map.img_x = 500;
	e->v_map.ecart = -42;
	e->v_map.cp = 74;
	e->v_map.cp_2 = 74;
	e->v_map.cst = 74;
	return (e);
}

int			main(int argc, const char **argv)
{
	t_env	e;
	int		x;
	int		y;

	if (initialise_stuct(&e, argc, argv) == NULL)
		return (-1);
	x = e.v_map.win_x;
	y = e.v_map.win_y;
	if ((e.win = mlx_new_window(e.mlx, x, y, "fdf")) == NULL)
		return (-1);
	ft_restart(&e);
	return (0);
}

int			ft_restart(t_env *e)
{
	new_img(e);
	fdf_calcul_proj(e->mapping, e);
	fdf_trace(e->mapping, e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, 1, 1);
	fdf_mlx(e);
	(void)e;
	return (1);
}
