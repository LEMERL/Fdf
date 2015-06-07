/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 17:45:22 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/07 14:04:17 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_col(t_trace t, t_env *e)
{
	(void)e;
	(void)t;
	return (0xFF0000);
}

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

int		start(t_env *e);

int			main(int argc, const char **argv)
{
	t_env	e;

	if (initialise_stuct(&e, argc, argv) == NULL)
		return (-1);
	if (start(&e) == -1)
		return (-1);
	return (0);
}

int		ft_restart(t_env *e)
{
	new_img(e);
	fdf_calcul_proj(e->mapping, e);
	fdf_trace(e->mapping, e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, 1, 1);
	fdf_mlx(e);
	return (1);
}

int		start(t_env *e)
{
	int		x;
	int		y;

	x = e->v_map.win_x;
	y = e->v_map.win_y;
	if (e->win != NULL)
		mlx_destroy_window(e->mlx, e->win);
	if ((e->win = mlx_new_window(e->mlx, x, y, "fdf")) == NULL)
		return (-1);//ft_error("allocation failled")
	new_img(e);
	ft_restart(e);
	return (1);
}
