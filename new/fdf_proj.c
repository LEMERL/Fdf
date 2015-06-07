//2.000.000.000
//.......20.000

#include "fdf.h"

void	ft_calc_aff(t_fdf *strc, t_env *e, int ecart)
{
	if ((e->proj_type == 0) && (strc->x >= 0))
	{
		strc->print_x = (strc->iso_x * ecart) / 100;
		strc->print_y = (strc->iso_y * ecart) / 100;
	}
	else if (strc->x >= 0)
	{
		strc->print_x = (strc->paral_x * ecart) / 100;
		strc->print_y = (strc->paral_y * ecart) / 100;
	}
	strc->print_x += e->v_map.img_x;
	strc->print_y = strc->print_y + e->v_map.img_y;
}

void	fdf_calcul_proj(t_fdf **s, t_env *env)
{
	int			i;
	int			j;

	if (env->v_map.ecart == -42 && ((i = -1) + 2))
	{
		while (s[++i] && ((j = -1) + 2))
			while (s[i][++j].x >= 0)
			{
				ft_proj_cal(s[i] + j, env);
				if ((i == 0 && j == 0) || env->v_map.low_x > s[i][j].iso_x)
					env->v_map.low_x = s[i][j].iso_x;
				if ((i == 0 && j == 0) || env->v_map.low_y > s[i][j].iso_y)
					env->v_map.low_y = s[i][j].iso_y;
				if ((i == 0 && j == 0) || env->v_map.max_x < s[i][j].iso_x)
					env->v_map.max_x = s[i][j].iso_x;
				if ((i == 0 && j == 0) || env->v_map.max_y > s[i][j].iso_x)
					env->v_map.max_y = s[i][j].iso_y;
			}
		env->v_map.ecart = ((env->v_map.max_x + env->v_map.max_y) -
				(env->v_map.low_x + env->v_map.low_y)) /
			((env->v_map.win_x + env->v_map.win_y) * 130);
		env->v_map.win_x = 0;
		env->v_map.win_y = 0;
	}
	if (env->v_map.ecart >= 100)
		env->v_map.ecart = 100;
	if (env->v_map.ecart <= 0)
		env->v_map.ecart = 1;
	i = -1;
	while (s[++i] && ((j = -1) + 2))
		while (s[i][++j].x >= 0)
			ft_calc_aff(s[i] + j, env, env->v_map.ecart);
}

void	ft_proj_cal(t_fdf *strc, t_env *e)
{
	int		cst_1;
	int		cst_2;
	int		cst;

	(void)e;
	cst_1 = e->v_map.cp;
	cst_2 = e->v_map.cp_2;
	cst = e->v_map.cst;
	if (strc->x >= 0)
	{
		strc->iso_x = (cst_1 * strc->x) - (cst_2 * strc->y);
		strc->iso_y = -strc->z * 20 + (cst_1 / 2) * strc->x + (cst_2 / 2) * strc->y;
		strc->paral_x = 100 * strc->x + (cst * strc->z) / 2;
		strc->paral_y = 100 * strc->y + (cst * strc->z) / 2;
	}
}

/*	if (strc.aff_x > e->v_map.max_x || (j == 0 && i == 0))
		e->v_map.max_x = strc.aff_x;
	if (strc.aff_x < e->v_map.low_x || (j == 0 && i == 0))
		e->v_map.low_x = strc.aff_x;
	if (strc.aff_y > e->v_map.max_y || (j == 0 && i == 0))
		e->v_map.max_y = strc.aff_y;
	if (strc.aff_y < e->v_map.low_y || (j == 0 && i == 0))
		e->v_map.low_y = strc.aff_y;
	if (strc.z > e->v_map.max_z || (j == 0 && i == 0))
		e->v_map.max_z = strc.z;
	if (strc.z < e->v_map.low_z || (j == 0 && i == 0))
		e->v_map.low_z = strc.z;
	return (strc);*/

//		map->ecart = map->win_x / (map->max_x + 1 - map->low_x);
//		if (map->ecart > (map->win_y / (map->max_y + 1 - map->low_y)))
//			map->ecart = map->win_y / (map->max_y + 1 - map->low_y);
//
//			s[i][j].print_x = s[i][j].aff_x - map->low_x;
//			s[i][j].aff_y = s[i][j].aff_y - map->low_y;
//			s[i][j].aff_c = ft_color_pick(*map, env->var_color, &(s[i][j]));
