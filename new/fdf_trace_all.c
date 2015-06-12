/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_trace_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:43:53 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 21:50:25 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_trace_one(t_fdf **s, t_env *env)
{
	static int		i = 255;
	int				n;
	int				m;

	if (((s[0][0].x < 0) || (s[0][1].x < 0)) && (s[1] == NULL || s[1][0].x < 0))
	{
		if (env->v_map.ecart <= 0)
			env->v_map.ecart = 2;
		n = -1 - env->v_map.ecart / 2;
		m = n;
		if (s[0][0].x >= 0 && (i = i + 16 * 256 + 8 * 256))
			while (++n < env->v_map.ecart / 2 && (m = -env->v_map.ecart / 2))
			{
				while (++m < env->v_map.ecart / 2)
					img_pixel_put(env, 500 + n + env->v_map.img_x,
							500 + m + env->v_map.img_y, i);
			}
		else
		{
			ft_putendl_fd("ERROR: Empty map", 2);
			ft_wait_exit(1);
		}
		return (0);
	}
	return (1);
}

void			fdf_trace(t_fdf **s, t_env *env)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (fdf_trace_one(s, env))
		while (s[i])
		{
			j = 0;
			while (s[i][j].x >= 0)
			{
				k = 0;
				if (s[i][j + 1].x >= 0)
					ft_trace_segm(s[i][j], s[i][j + 1], env);
				while (s[i + 1] && s[i + 1][k].x >= 0 && (k != j + 1))
				{
					if (k == j && s[i + 1][k].x >= 0)
						ft_trace_segm(s[i][j], s[i + 1][j], env);
					k++;
				}
				j++;
			}
			i++;
		}
}

void			ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env)
{
	int			e;
	t_trace		t;

	t = fdf_trace_initial_struct(p1, p2);
	if (t.ref_prog == 0)
		t.ref_prog = 1;
	e = 0;
	if (t.dx > 0 && t.dy > 0)
		trace_1(t, e, env);
	else if (t.dx > 0 && t.dy < 0)
		trace_4(t, e, env);
	else if (t.dx < 0 && t.dy > 0)
		trace_2(t, e, env);
	else if (t.dx < 0 && t.dy < 0)
		trace_3(t, e, env);
	else if (t.dx == 0 || t.dy == 0)
		trace_0(t, env);
	img_pixel_put(env, t.x2, t.y2, t.c2);
}

t_trace			fdf_trace_initial_struct(t_fdf p1, t_fdf p2)
{
	t_trace		t;

	t.dx = (int)(p2.print_x - p1.print_x) * 2;
	t.dy = (int)(p2.print_y - p1.print_y) * 2;
	t.x1 = (int)p1.print_x;
	t.x2 = (int)p2.print_x;
	t.y1 = (int)p1.print_y;
	t.y2 = (int)p2.print_y;
	t.c1 = p1.color;
	t.c2 = p2.color;
	t.z1 = p1.z;
	t.z2 = p2.z;
	t.ref_prog = (((t.dx * t.dx) + (t.dy * t.dy)) / 4);
	return (t);
}
