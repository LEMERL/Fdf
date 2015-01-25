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

t_fdf	fdf_proj_paral(t_fdf strc, int cst)
{
	if (strc.x >= 0)
	{
		strc.aff_x = strc.x + (cst * strc.z) / 100;
		strc.aff_y = strc.y + ((cst * strc.z) / 200);
	}
	return (strc);
}
