#include "fdf.h"

/*
 *
 * fdf_proj_iso prend en param les coordonnees telles que recues sur la map
 * et calcule les coordonnees (aff_x et aff_y) pour l'affichage en mode isometrique
 *
 * c1 et c2 doivent etre entre 0.5 et 1
 *
 *	aff_x = (c1 * x) - (c2 * y);
 *	aff_y = z + ((c1 * x) / 2) + ((c2 * y) / 2);
 *
 */

t_fdf	***fdf_proj_iso(t_fdf ***map, int c1, int c2)
{
	void	**ptr;
	void	***tab;
	t_fdf	*st;

	tab = (void***)*map;
	while (tab != NULL)
	{
		ptr = *tab;
		while (ptr != NULL)
		{
			st = (t_fdf*)*ptr;
			if (st != NULL)
			{
				st->aff_x = ((c1 * st->x) - (c2 * st->y) / 100);
				st->aff_y = st->z + ((c1 * st->x) / 2) + ((c2 * st->y) / 2);
				st->aff_y = st->aff_y / 100;
			}
			ptr++;
		}
		tab = tab + 1;
	}
	return (map);
}

/*
 *
 * fdf_proj_paral prend en param les coordonnees telles que recues sur la map
 * et calcule les coordonnees (aff_x et aff_y) pour l'affichage en mode parallele
 *
 * cst doit etre entre 50 et 100
 *
 *	aff_x = x + cst * z;
 *	aff_y = y + ((cst * z) / 2);
 *
 */

t_fdf	***fdf_proj_paral(t_fdf ***map, int cst)
{
	void	**ptr;
	void	***tab;
	t_fdf	*st;

	tab = (void***)*map;
	while (tab != NULL)
	{
		ptr = *tab;
		while (ptr != NULL)
		{
			st = (t_fdf*)*ptr;
			if (st != NULL)
			{
				st->aff_x = st->x + (cst * st->z) / 100;
				st->aff_y = st->y + ((cst * st->z) / 200);
			}
			ptr++;
		}
		tab = tab + 1;
	}
	return (map);
}
