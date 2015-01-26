/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:52:21 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/26 11:47:06 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
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
	int				ref_prog;
}					t_trace;


t_fdf				**fdf_mapping(int argc, const char *argv[]);
t_fdf				**get_map(int fd);
t_fdf				*ft_strtofdf(const char *s, int line);
void				ft_double_tab_del(void **tab);

# define ISO 1
void				fdf_calcul_proj(t_fdf **s, t_env *env);
# define ISO_C1 75
# define ISO_C2 75
t_fdf				fdf_proj_iso(t_fdf strc, int c1, int c2);
t_fdf				fdf_proj_paral(t_fdf strc, int cst);
# define PARAL_CST 75

void				fdf_trace(t_fdf **s, t_env *env);
void				ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env);
t_trace				fdf_trace_initial_struct(t_fdf p1, t_fdf p2);
void				trace_0(t_trace t, t_env *env);
void				trace_1(t_trace t, int e, t_env *env);
void				trace_2(t_trace t, int e, t_env *env);
void				trace_3(t_trace t, int e, t_env *env);
void				trace_4(t_trace t, int e, t_env *env);

# define DEGRADE_PC 4
int					ft_col(t_trace t);

# define MAX_X 200
# define MAX_Y 200

t_env		fdf_mlx(t_env *env, t_fdf **map);


#endif
