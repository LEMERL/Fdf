/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 17:45:22 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/08 16:33:03 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_col(t_trace t, t_env *e)
{
	(void)e;
	(void)t;
	return (0xFF0000);
}

void		ft_exit(int n)
{
	wait(NULL);
	exit(n);
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
	e->img = NULL;
	e->proj_type = 1;
	e->v_map.win_x = 1000;
	e->v_map.win_y = 1000;
	e->v_map.ecart = -42;
	e->v_map.cp = 74;
	e->v_map.cp_2 = 74;
	e->v_map.cst = 74;
	return (e);
}
int	signal_handler(int signu)
{

//wait4(nonblockant)
}
int		check_fork(int argc, char **argv)
{
	t_pid	current_pid;
	t_env	e;
	int		x;
	int		y;

	current_pid = 1;
	if (argc > 2)
		current_pid = fork();
	if (current_pid == -1)
		exit(-1);
	else if (current_pid == 0)//in forked process (child)
		check_fork(argc - 1, argv + 1);
	else
	{
		signal(sigchild, signal_handler)
		if (initialise_stuct(&e, argc, argv) == NULL)
			return (-1);
		x = e.v_map.win_x;
		y = e.v_map.win_y;
		if ((e.win = mlx_new_window(e.mlx, x, y, "fdf")) == NULL)
			return (-1);
		ft_restart(&e);
	}
}

int			main(int argc, const char **argv)
{
	if (check_fork(argc, argv) == -1)
		return (-1);
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
	return (1);
}
