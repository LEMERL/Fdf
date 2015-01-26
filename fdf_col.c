#include "fdf.h"

int		ft_col(t_trace t)
{
	int		prog;
	int		tmp;
	t_color	verif;

	tmp = (((t.x2 - t.x1) * (t.x2 - t.x1)) + ((t.y2 - t.y1) * (t.y2 - t.y1)));
	prog = ((tmp * 255) / t.ref_prog) / DEGRADE_PC;
	prog = prog * DEGRADE_PC;
	if ((((tmp * 255) / t.ref_prog) % DEGRADE_PC) >= (DEGRADE_PC / 2))
		prog = prog + DEGRADE_PC;
	if (prog > 255)
		prog = 255;
	verif.red = ((t.c1.red * prog + t.c2.red * (255 - prog)) * 256 * 256);
	verif.green = (t.c1.green * prog + t.c2.green * (255 - prog)) * 256;
	verif.blue = (t.c1.blue * prog + t.c2.blue * (255 - prog));
	verif.color = (verif.blue) / 255 + verif.green / 255 + verif.red / 255;
	return (verif.color);
}
