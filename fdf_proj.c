#include "fdf.h"

void	agr(t_fdf *strc)
{
	strc->x = strc->x * CST_ECART;
	strc->y = strc->y * CST_ECART;
	strc->z = strc->z * CST_ECART;
}

void	fdf_calcul_proj(t_fdf **s, t_env *env)
{
	int		i;
	int		j;

	(void)env;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j].x >= 0)
		{
			agr(&(s[i][j]));
			if (ISO == 1)
				fdf_proj_iso(&(s[i][j]), ISO_C1, ISO_C2);
			else
				fdf_proj_paral(&(s[i][j]), PARAL_CST);
			j++;
		}
		i++;
	}
}

void	fdf_proj_iso(t_fdf *strc, int c1, int c2)
{
	if (strc->x >= 0)
	{
		strc->aff_x = ((c1 * strc->x) - (c2 * strc->y)) / 100;
		strc->aff_y = strc->z + ((c1 * strc->x) + (c2 * strc->y)) / 2;
		strc->aff_y = strc->aff_y / 100;
	}
}

void	fdf_proj_paral(t_fdf *strc, int cst)
{
	if (strc->x >= 0)
	{
		strc->aff_x = strc->x + (cst * strc->z) / 200;
		strc->aff_y = strc->y + ((cst * strc->z) / 100);
	}
}
