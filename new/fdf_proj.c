/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:43:47 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 21:43:48 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				ft_proj_cal(s[i] + j, env);
		env->v_map.img_x = 0;
		env->v_map.img_y = 0;
		env->v_map.ecart = 20;
	}
	if (env->v_map.ecart >= 100)
		env->v_map.ecart = 100;
	if (env->v_map.ecart <= 2)
		env->v_map.ecart = 2;
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
		strc->iso_y = -strc->z * 20 +
			(cst_1 / 2) * strc->x + (cst_2 / 2) * strc->y;
		strc->paral_x = 100 * strc->x + (cst * strc->z) / 2;
		strc->paral_y = 100 * strc->y + (cst * strc->z) / 2;
	}
}
