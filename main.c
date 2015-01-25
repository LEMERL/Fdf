#include "libft/includes/get_next_line.h"
#include "fdf.h"
#include <fcntl.h>

int		main(int argc, const char *argv[])
{
	t_fdf	**s;
	t_env	*env;

	*env = NULL;
	s = fdf_mapping(argc, argv);
	fdf_mlx(env, s);
	ft_double_tab_del(s);
	return (0);
}
