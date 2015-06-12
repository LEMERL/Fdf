/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 22:17:14 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/12 09:36:03 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <signal.h>

int		ft_restart(t_env *e)
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

void	sign_hand(int signnum)
{
	(void)signnum;
	wait4(0, 0, WNOHANG, 0);
}

void	gestion_multi(int argc, const char **argv)
{
	pid_t		pid;

	signal(SIGCHLD, sign_hand);
	pid = 1;
	if (argc > 2 && (pid = fork()) < 0)
		exit(0);
	if (pid == 0)
	{
		gestion_multi(argc - 1, argv);
		ft_wait_exit(0);
	}
	else
	{
		start(argc, argv);
		ft_wait_exit(0);
	}
}

void	ft_wait_exit(int n)
{
	wait(NULL);
	exit(n);
}
