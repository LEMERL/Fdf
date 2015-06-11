/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:43:08 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 22:05:52 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "libft/includes/libft.h"

typedef struct		s_v_map
{
	int				ecart;
	int				cst;
	int				cp;
	int				cp_2;
	int				win_x;
	int				win_y;
	int				img_x;
	int				img_y;
	int				set;
	int				ground;
	int				underground;
	int				high;
}					t_v_map;

typedef struct		s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	int				color;
}					t_color;

typedef struct		s_var_color
{
	int				col_flag;
	int				degradee;
	t_color			col_underground;
	t_color			col_ground_underground;
	t_color			col_ground;
	t_color			col_ground_high;
	t_color			col_high;
}					t_var_color;

typedef struct		s_fdf
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				paral_x;
	int				paral_y;
	int				iso_x;
	int				iso_y;
	int				print_x;
	int				print_y;
	t_color			aff_c;
	int				tmp;
}					t_fdf;

typedef struct		s_trace
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				c1;
	int				c2;
	int				z1;
	int				z2;
	int				ref_prog;
}					t_trace;

typedef struct		s_img
{
	void			*ptr;
	int				width;
	int				height;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_fdf			**mapping;
	t_v_map			v_map;
	t_var_color		var_color;
	int				proj_type;
}					t_env;

void				set_color(t_env *e, int high, int ground, int underground);
t_env				*fdf_strc_ini(t_env *e, int argc, const char **argv);
int					ft_restart(t_env *e);
t_fdf				**fdf_mapping(int argc, const char *argv[]);
t_fdf				**get_map(int fd, int j);
t_fdf				*ft_strtofdf(const char *s, int line, int i);
void				fdf_calcul_proj(t_fdf **s, t_env *env);
void				ft_proj_cal(t_fdf *strc, t_env *e);
void				fdf_trace(t_fdf **s, t_env *env);
void				ft_trace_segm(t_fdf p1, t_fdf p2, t_env *env);
t_trace				fdf_trace_initial_struct(t_fdf p1, t_fdf p2);
void				trace_0(t_trace t, t_env *env);
void				trace_1(t_trace t, int e, t_env *env);
void				trace_2(t_trace t, int e, t_env *env);
void				trace_3(t_trace t, int e, t_env *env);
void				trace_4(t_trace t, int e, t_env *env);
void				test_get_map(t_fdf **s, t_env *e);
t_color				ft_color_pick(t_v_map cst, t_var_color vcol, t_fdf *strc);
int					img_pixel_put(t_env *e, int x, int y, int color);
int					ft_col(t_trace t, t_env *e);
t_color				ft_degradee(t_color c1, t_color c2, int p, int ref_prog);
t_color				ft_inttocolstrc(int color);
void				new_img(t_env *e);
void				key_hook2(t_env *env, int keycode);
t_env				fdf_mlx(t_env *env);

#endif
