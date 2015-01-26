#include "fdf.h"

void	fdf_calcul_proj(t_fdf **s, t_env *env)
{
	int		i;
	int		j;

	(void)env;

	i = 0;
	while ((j = 0) && s[i] && (i++))
	{
		while (s[i][j].x >= 0)
		{
			if (ISO == 1)
				fdf_proj_iso(s[i][j], ISO_C1, ISO_C2);
			else
				fdf_proj_paral(s[i][j], PARAL_CST);
			j++;
		}
	}
}

t_fdf	fdf_proj_iso(t_fdf strc, int c1, int c2)
{
	if (strc.x >= 0)
	{
		strc.aff_x = ((c1 * strc.x) - (c2 * strc.y) / 100);
		strc.aff_y = strc.z + ((c1 * strc.x) / 2) + ((c2 * strc.y) / 2);
		strc.aff_y = strc.aff_y / 100;
	}
	return (strc);
}

t_fdf	fdf_proj_paral(t_fdf strc, int cst)
{
	if (strc.x >= 0)
	{
		strc.aff_x = strc.x + (cst * strc.z) / 100;
		strc.aff_y = strc.y + ((cst * strc.z) / 200);
	}
	return (strc);
}
