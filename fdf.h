/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:52:21 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/04 14:14:34 by mgrimald         ###   ########.fr       */
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


typedef struct		s_var_map
{
	int				max_x;
	int				low_x;
	int				max_y;
	int				low_y;
	int				max_z;
	int				low_z;
	int				ecart;
	int				win_x;
	int				win_y;
}					t_var_map;

typedef struct		s_var_color
{
	int				col_flag;//0 = FULL WHITE, 1 = original color, 2 = personalisable color sauf specifiee, 3 = full personalisable
	int				degradee;//0 = no, sinon : niveau de progression x/255
	int				col_underground;//if (col_flag == 2/3)
	int				col_ground;//if (color flag == 2/3) : defini couleur du niveau 0
	int				col_high;//if (color flag == 2/3) : defini couleur du plus haut niveau
}					t_var_color;

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

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_fdf			**mapping;
	t_var_map		var_map;
	t_var_color		var_color;
	int				proj_type;//0 = iso, 1 = paral;
}					t_env;

t_env				*fdf_strc_ini(t_env *e, int argc, const char **argv);
int					ft_restart(t_env *e);

t_fdf				**fdf_mapping(int argc, const char *argv[]);
t_fdf				**get_map(int fd);
t_fdf				*ft_strtofdf(const char *s, int line);
void				ft_double_tab_del(void **tab);

void				fdf_calcul_proj(t_fdf **s, t_env *env);
t_fdf				ft_proj_cal(t_fdf strc, t_env *e, int i, int j);

void				fdf_trace(t_fdf **s, t_env *env);
void				ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env);
t_trace				fdf_trace_initial_struct(t_fdf p1, t_fdf p2);
void				trace_0(t_trace t, t_env *env);
void				trace_1(t_trace t, int e, t_env *env);
void				trace_2(t_trace t, int e, t_env *env);
void				trace_3(t_trace t, int e, t_env *env);
void				trace_4(t_trace t, int e, t_env *env);

int					ft_col(t_trace t, t_env *e);

t_env		fdf_mlx(t_env *env);


#endif
