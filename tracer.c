typedef struct	s_trace
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			dx;
	int			dy;
}				t_trace;

void	ft_trace_segm(int x1, int y1, int x2, int y2)
{
	int			e;
	t_trace		t;

	t.dx = (x2 - x1) * 2;
	t.dy = (y2 - y1 ) * 2;
	t.x1 = x1;
	t.x2 = x2;
	t.y1 = y1;
	t.y2 = y2;
		if (t.dx > 0 && t.dy > 0)
			{
				if (t.dx >= t.dy) //premier octant
				{
					e = t.dx / 2;
					while (t.x1 != t.x2)
					{
						//mlx_put_pixel(t.x1, t.y1);
						t.x1 = t.x1 + 1;
						e = e - t.dy;
						if (e < 0)
						{
							t.y1 = t.y1 + 1;
							e = e + t.dx;
						}
					}
				}
				else //(t.dx < t.dy) ==> second octant
				{
					e = t.dy / 2;
					while (t.y1 != t.y2)
					{
						//mlx_put_pixel(t.x1, t.y1);
						t.y1 = t.y1 + 1;
						e = e - t.dy;
						if (e < 0)
						{
							t.x1 = t.x1 + 1;
							e = e + t.dy;
						}
					}
				}
			}
		else if (t.dx > 0 && t.dy < 0)//(t.dy < 0 et t.dx > 0) ==> 4* quadrant
			{
				if (t.dx >= -t.dy) //8* octant
				{
					e = t.dx / 2;
					while (t.x1 != t.x2)
					{
					//mlx_put_pixel(t.x1, t.y1);
						t.x1 = t.x1 + 1;
						e = e - t.dx;
						if (e < 0)
						{
							t.y1 = t.y1 - 1;
							e = e + t.dx;
						}
					}
				}
				else //7* octant
				{
					e = t.dx / 2;
					while (t.y1 != t.y2)
					{
						//mlx_put_pixel(t.x1, t.y1);
						t.y1 = t.y1 - 1;
						e = e + t.dx;
						if (e > 0)
						{
							t.x1 = t.x1 + 1;
							e = e + t.dy;
						}
					}
				}
			}
		else if (t.dx < 0 && t.dy > 0)
			{
				if (-t.dx >= t.dy) //4* octant
				{
					e = t.dx / 2;
					while (t.x1 != t.x2)
					{
						//mlx_put_pixel(t.x1, t.y1);
						t.x1 = t.x1 - 1;
						e = e + t.dy;
						if (e >= 0)
						{
							t.y1 = t.y1 + 1;
							e = e + t.dx;
						}
					}
				}
				else //3* octant
				{
					e = t.dy / 2;
					while (t.y1 != t.y2)
					{
						//mlx_put_pixel(t.x1, t.y1);
						t.y1 = t.y1 + 1;
						e = e + t.dx;
						if (e <= 0)
						{
							t.x1 = t.x1 - 1;
							e = e + t.dy;
						}
					}
				}
			}
	else if (t.dx < 0 && t.dy < 0)
		trace_quad_3(t, e);
	else if (t.dx == 0 || t.dy == 0)
		trace_0(t, e);
	//mlx_put_pixel(t.x2, t.y2);
}

void	trace_quad_1(t_trace t, int e)
;
void	trace_quad_2(t_trace t, int e)
;
void	trace_quad_4(t_trace t, int e)
;
void	trace_quad_3(t_trace t, int e)
{
	if (t.dx <= t.dy)//5* octant
	{
		e = t.dx / 2;
		while (t.x1 != t.x2)
		{
			//mlx_put_pixel(t.x1, t.y1);
			t.x1 = t.x1 - 1;
			e = e - t.dy;
			if (e >= 0)
			{
				t.y1 = t.y1 - 1;
				e = e + t.dx;
			}
		}
	}
	else//6* octant
	{
		e = t.dy / 2;
		while (t.y1 != t.y2)
		{
			//mlx_put_pixel(t.x1, t.y1);
			t.y1 = t.y1 - 1;
			e = e - t.dx;
			if (e >= 0)
			{
			t.x1 = t.x1 - 1;
			e = e + t.dy;
			}
		}
	}
}

void	trace_0(t_trace t, int e)
	{
		while (t.y1 != t.y2 && t.dx == 0)
		{
			//mlx_put_pixel(t.x1, t.y1);
			if (t.dy > 0)
				t.y1 = t.y1 + 1;
			if (t.dy < 0)
				t.y1 = t.y1 - 1;
		}
		while (t.x1 != t.x2 && t.dy == 0)
		{
			//mlx_put_pixel(t.x1, t.y1);
			if (t.dx > 0)
				t.x1 = t.x1 + 1;
			if (t.dx < 0)
				t.x1 = t.x1 - 1;
		}
	}
