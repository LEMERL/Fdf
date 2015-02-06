#include "fdf.h"

int		ft_col(t_trace t, t_env *e)
{
	int			prog;
	int			tmp;
	t_color		verif;
	t_var_color	vcol;

	vcol = e->var_color;
	tmp = (((t.x2 - t.x1) * (t.x2 - t.x1)) + ((t.y2 - t.y1) * (t.y2 - t.y1)));
	if (vcol.degradee > 0)
	{
		prog = ((tmp * 255) / t.ref_prog) / vcol.degradee;
		prog = prog * vcol.degradee;
		if ((((tmp * 255) / t.ref_prog) % vcol.degradee) >= (vcol.degradee / 2))
			prog = prog + vcol.degradee;
		if (prog > 255)
			prog = 255;
		verif.red = ((t.c1.red * prog + t.c2.red * (255 - prog)) * 256 * 256);
		verif.green = (t.c1.green * prog + t.c2.green * (255 - prog)) * 256;
		verif.blue = (t.c1.blue * prog + t.c2.blue * (255 - prog));
		verif.color = (verif.blue) / 255 + verif.green / 255 + verif.red / 255;
	}
	else
		verif.color = t.c1.color;
	if (verif.color < 0 || verif.color >= 0x1000000)
		verif.color = 0xFFFFFF;
	return (verif.color);
}
