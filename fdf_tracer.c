#include "fdf.h"

int		ft_col(t_trace t)
{
	int		prog;
	int		tmp;
	t_color	verif;

	tmp = (((t.x2 - t.x1) * (t.x2 - t.x1)) + ((t.y2 - t.y1) * (t.y2 - t.y1)));
	prog = ((tmp * 255) / t.ref_prog) / DEGRADE_PC;
	prog = prog * DEGRADE_PC;
	if ((((tmp * 255) / t.ref_prog) % DEGRADE_PC) >= (DEGRADE_PC / 2))
		prog = prog + DEGRADE_PC;
	if (prog > 255)
		prog = 255;
	verif.red = ((t.c1.red * prog + t.c2.red * (255 - prog)) * 256 * 256);
	verif.green = (t.c1.green * prog + t.c2.green * (255 - prog)) * 256;
	verif.blue = (t.c1.blue * prog + t.c2.blue * (255 - prog));
	verif.color = (verif.blue) / 255 + verif.green / 255 + verif.red / 255;
	return (color);
}

t_trace	ft_fdf_initial_struct(t_fdf p1, t_fdf p2)
{
	t_trace		t;

	t.dx = (p2.aff_x - p1.aff_x) * 2;
	t.dy = (p2.aff_y - p1.aff_y) * 2;
	t.x1 = p1.aff_x;
	t.x2 = p2.aff_x;
	t.y1 = p1.aff_y;
	t.y2 = p2.aff_y;
	t.c1.color = p1.color;
	t.c2.color = p2.color;
	t.c1.red = t.c1.color / (256 * 256);
	t.c1.green = (t.c1.color / 256) % 256;
	t.c1.blue = t.c1.color % (256);
	t.c2.red = t.c2.color / (256 * 256);
	t.c2.green = (t.c2.color / 256) % 256;
	t.c2.blue = (t.c2.color % 256);
	t.ref_prog = (((t.dx * t.dx) + (t.dy * t.dy)) / 4);
}

void	ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env)
{
	int			e;
	t_trace		t;

	//t.ref_prog = sqrt(((t.dx * t.dx) + (t.dy * t.dy)) / 4);
	t = ft_fdf_initial_struct(p1, p2);
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
	mlx_pixel_put(env->mlx, env->win, t.x2, t.y2, t.c2);
}

void	trace_1(t_trace t, int e, t_env *env)
{
	if (t.dx >= t.dy && (e = t.dx / 2))//premier octant
		while (t.x1 != t.x2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.x1 = t.x1 + 1;
			if ((e = e - t.dy) < 0)
			{
				t.y1 = t.y1 + 1;
				e = e + t.dx;
			}
		}
	else if (t.dx < t.dy && (e = t.dy / 2))//(t.dx < t.dy) ==> second octant
		while (t.y1 != t.y2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.y1 = t.y1 + 1;
			if ((e = e - t.dx) < 0)
			{
				t.x1 = t.x1 + 1;
				e = e + t.dy;
			}
		}
}

void	trace_2(t_trace t, int e, t_env *env)
{
	if ((t.dx * -1) >= t.dy && (e = t.dx / 2))//4* octant
		while (t.x1 != t.x2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.x1 = t.x1 - 1;
			if ((e = e + t.dy) >= 0)
			{
				t.y1 = t.y1 + 1;
				e = e + t.dx;
			}
		}
	else if (-t.dx < t.dy && (e = t.dy / 2))//3* octant
		while (t.y1 != t.y2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.y1 = t.y1 + 1;
			if ((e = e + t.dx) <= 0)
			{
				t.x1 = t.x1 - 1;
				e = e + t.dy;
			}
		}
}

void	trace_4(t_trace t, int e, t_env *env)
{
	if (t.dx >= -t.dy && (e = t.dx / 2))//8* octant
		while (t.x1 != t.x2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.x1 = t.x1 + 1;
			if ((e = e + t.dy) < 0)
			{
				t.y1 = t.y1 - 1;
				e = e + t.dx;
			}
		}
	else//7* octant
	{
		e = t.dx / 2;
		while (t.y1 != t.y2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.y1 = t.y1 - 1;
			if ((e = e + t.dx) > 0)
			{
				t.x1 = t.x1 + 1;
				e = e + t.dy;
			}
		}
	}
}

void	trace_3(t_trace t, int e, t_env *env)
{
	if (t.dx <= t.dy && (e = t.dx / 2))//5* octant
		while (t.x1 != t.x2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.x1 = t.x1 - 1;
			if ((e = e - t.dy) >= 0)
			{
				t.y1 = t.y1 - 1;
				e = e + t.dx;
			}
		}
	else if (t.dx > t.dy && (e = t.dy / 2))//6* octant
		while (t.y1 != t.y2)
		{
			mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
			t.y1 = t.y1 - 1;
			if ((e = e - t.dx) >= 0)
			{
				t.x1 = t.x1 - 1;
				e = e + t.dy;
			}
		}
}

void	trace_0(t_trace t, t_env *env)
{
	while (t.y1 != t.y2 && t.dx == 0)
	{
		mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
		if (t.dy > 0)
			t.y1 = t.y1 + 1;
		if (t.dy < 0)
			t.y1 = t.y1 - 1;
	}
	while (t.x1 != t.x2 && t.dy == 0)
	{
		mlx_pixel_put(env->mlx, env->win, t.x1, t.y1, ft_col(t));
		if (t.dx > 0)
			t.x1 = t.x1 + 1;
		if (t.dx < 0)
			t.x1 = t.x1 - 1;
	}
}
