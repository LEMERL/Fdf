#include "fdf.h"

void	fdf_trace(t_fdf **s, t_env *env)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j].x >= 0)
		{
			k = 0;
			if (s[i][j + 1].x >= 0)
				ft_trace_segm(s[i][j], s[i][j + 1], env);
			while (s[i + 1] && s[i][k].x >= 0 && (k != j + 1))
			{
				if (k == j)
					ft_trace_segm(s[i][j], s[i + 1][j], env);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env)
{
	int			e;
	t_trace		t;

	//t.ref_prog = sqrt(((t.dx * t.dx) + (t.dy * t.dy)) / 4);
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
	mlx_pixel_put(env->mlx, env->win, t.x2, t.y2, t.c2.color);
}

t_trace	fdf_trace_initial_struct(t_fdf p1, t_fdf p2)
{
	t_trace		t;

	t.dx = (int)(p2.aff_x - p1.aff_x) * 2;
	t.dy = (int)(p2.aff_y - p1.aff_y) * 2;
	t.x1 = (int)p1.aff_x;
	t.x2 = (int)p2.aff_x;
	t.y1 = (int)p1.aff_y;
	t.y2 = (int)p2.aff_y;
	t.c1.color = p1.color;
	t.c2.color = p2.color;
	t.c1.red = t.c1.color / (256 * 256);
	t.c1.green = (t.c1.color / 256) % 256;
	t.c1.blue = t.c1.color % (256);
	t.c2.red = t.c2.color / (256 * 256);
	t.c2.green = (t.c2.color / 256) % 256;
	t.c2.blue = (t.c2.color % 256);
	t.ref_prog = (((t.dx * t.dx) + (t.dy * t.dy)) / 4);
	return (t);
}
