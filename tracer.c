#include "fdf.h"

int		ft_col(t_trace, t_fdf )
{
	int		color;

	c1 -> c2;
	return (color);
}

void	ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env)
{
	int			e;
	t_trace		t;

	t.dx = (p2.aff_x - p1.aff_x) * 2;
	t.dy = (p2.aff_y - p1.aff_y) * 2;
	t.x1 = p1.aff_x;
	t.x2 = p2.aff_x;
	t.y1 = p1.aff_y;
	t.y2 = p2.aff_y;
	t.c1 = p1.color;
	t.c2 = p2.color;
	e = 0;
	if (t.dx > 0 && t.dy > 0)
		trace_1(t, e, env);
	else if (t.dx > 0 && t.dy < 0)//(t.dy < 0 et t.dx > 0) ==> 4* quadrant
		trace_4(t, e, env);
	else if (t.dx < 0 && t.dy > 0)
		trace_2(t, e, env);
	else if (t.dx < 0 && t.dy < 0)
		trace_3(t, e, env);
	else if (t.dx == 0 || t.dy == 0)
		trace_0(t, env);
	mlx_pixel_put(env->mlx, env->win, t.x2, t.y2, ft_col(t));
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
