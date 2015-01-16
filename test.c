/* ************************************************************************** */
/*                                                                            */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 19:24:05 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/15 14:39:15 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_X 255
#define MAX_Y 255

typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;

int	draw(t_env *e, t_map *map)
{
	t_aff	*aff;

	aff = (map);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	(void)e;
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int	expose_hook(t_env *e, t_map ***map)
{
	t_aff ***aff;

		aff = fdf_proj_iso_struct(map)
		draw(e, );
	return (0);
}

int	main(void)
{
	t_env	e;
	t_map	***map;

	map = ft_get_map(/**/);

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, MAX_X, MAX_Y, "first_test");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
