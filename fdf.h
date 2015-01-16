#ifndef FDF_H
# define FDF_H

# define MAX_X 255
# define MAX_Y 255

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_fdf
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			aff_x;
	int			aff_y;
	int			aff_c;
}				t_fdf;

t_fdf			***fdf_proj_iso(t_fdf ***map, int c1, int c2);
t_fdf			***fdf_proj_paral(t_fdf ***map, int cst);

#endif
