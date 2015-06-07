/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 17:45:22 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/07 05:13:31 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*initialise_stuct(t_env *e, int argc, const char **argv)
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
	e->win = NULL;
	e->img = NULL;
	e->proj_type = 1;
	e->v_map.win_x = 1000;
	e->v_map.win_y = 1000;
	e->v_map.ecart = -42;
	e->v_map.img_x = 0;
	e->v_map.img_y = 0;
	e->v_map.cp = 74;
	e->v_map.cp_2 = 74;
	e->v_map.cst = 74;
	return (e);
}


int			main(int argc, const char **argv)
{
	t_env	e;

	if (initialise_stuct(&e, argc, argv) == NULL)
		return (-1);
	if (ft_restart(&e) == -1)
		return (-1);
	return (0);
}

int		ft_restart(t_env *e)
{
	static int		x = 0;
	static int		y = 0;

	if (x != e->v_map.win_x || y != e->v_map.win_y)
	{
		x = e->v_map.win_x;
		y = e->v_map.win_y;
		if (e->win != NULL)
			mlx_destroy_window(e->mlx, e->win);
		if ((e->win = mlx_new_window(e->mlx, x, y, "fdf")) == NULL)
			return (-1);//ft_error("allocation failled")
	}
	test_get_map(e->mapping, e);
	fdf_calcul_proj(e->mapping, e);
	new_img(e);
/*	if (e->v_map.img_x == -4200 || e->v_map.img_y == -4200)
	{
		e->v_map.img_x = (e->v_map.win_x - e->v_map.max_x + e->v_map.low_x) / 2;
		e->v_map.img_y = (e->v_map.win_y - e->v_map.max_y + e->v_map.low_y) / 2;
	}*/
	fdf_trace(e->mapping, e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, 0, 0);
//			e->v_map.img_x, e->v_map.img_y);
	fdf_mlx(e);
	return (1);
}
