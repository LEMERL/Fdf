/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:52:21 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/25 14:55:37 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX_X 200
# define MAX_Y 200

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "libft.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_fdf
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				aff_x;
	int				aff_y;
	int				aff_c;
}					t_fdf;

typedef struct		s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	int				color;
}					t_color;

typedef struct		s_trace
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	t_color			c1;
	t_color			c2;
}					t_trace;

t_fdf				fdf_proj_iso(t_fdf strc, int c1, int c2);
t_fdf				fdf_proj_paral(t_fdf strc, int cst);

t_trace				ft_fdf_initial_struct(t_fdf p1, t_fdf p2);
int					ft_col(t_trace t);

void				ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env);
void				trace_0(t_trace t, t_env *env);
void				trace_1(t_trace t, int e, t_env *env);
void				trace_2(t_trace t, int e, t_env *env);
void				trace_3(t_trace t, int e, t_env *env);
void				trace_4(t_trace t, int e, t_env *env);

t_fdf				**get_map(int fd);
t_fdf				*ft_strtofdf(const char *s, int line);

void				fdf_use_tab(t_fdf **s, t_env *env);

#endif
