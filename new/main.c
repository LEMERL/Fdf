/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 17:45:22 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/12 12:15:02 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_col(t_trace t, t_env *e)
{
	(void)e;
	(void)t;
	if (t.c1 > 0 && e->v_map.set == 0)
		return (t.c1);
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
		return (0x333333);
	}
	else
		return (0xFFFFFe);
}

void		set_color(t_env *e, int high, int ground, int underground)
{
	e->var_color.col_high.color = 0x00FFf0;
	e->var_color.col_ground_high.color = 0x006630;
	if ((e->v_map.high = high) + 1 && (high == 1))
	{
		e->var_color.col_high.color = 0xA11A1A;
		e->var_color.col_ground_high.color = 0x943C3C;
	}
	else if (high == 2)
	{
		e->var_color.col_high.color = 0x6a00c3;
		e->var_color.col_ground_high.color = 0x903080;
	}
	e->var_color.col_ground.color = 0xFFFF00;
	if ((e->v_map.ground = ground) + 1 && (ground == 1))
		e->var_color.col_ground.color = 0xC7C5C5;
	else if (ground == 2)
		e->var_color.col_ground.color = 0xFF00FF;
	e->var_color.col_ground_underground.color = 0xe08e66;
	e->var_color.col_underground.color = 0xf44681;
	if ((e->v_map.underground = underground) + 1 && (underground == 1))
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
	e->v_map.img_x = 250;
	e->v_map.img_y = 100;
	e->v_map.ecart = -42;
	e->v_map.cp = 74;
	e->v_map.cp_2 = 74;
	e->v_map.cst = 74;
	return (e);
}

void		start(int argc, const char **argv)
{
	t_env	*e;
	int		x;
	int		y;

	e = (t_env*)ft_strnew(sizeof(t_env));
	if (e == NULL)
	{
		ft_putendl_fd("Malloc error", 2);
		ft_wait_exit(-1);
	}
	if (initialise_stuct(e, argc, argv) == NULL)
		ft_wait_exit(-1);
	x = e->v_map.win_x;
	y = e->v_map.win_y;
	if ((e->win = mlx_new_window(e->mlx, x, y, "fdf")) == NULL)
		ft_wait_exit(-1);
	ft_restart(e);
}

int			main(int argc, const char **argv)
{
	if (argc < 2)
		ft_putendl_fd("Map error : I need a map", 2);
	else if (argc <= 2)
		start(argc, argv);
	else
		gestion_multi(argc, argv);
	return (0);
}
