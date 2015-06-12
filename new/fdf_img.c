/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:43:24 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 21:43:26 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			new_img(t_env *e)
{
	if (e->img != NULL)
	{
		if (e->img->ptr != NULL)
			mlx_destroy_image(e->mlx, e->img->ptr);
		free(e->img);
	}
	if ((e->img = (t_img*)malloc(sizeof(t_img))) == NULL)
		ft_wait_exit(0);
	e->img->width = e->v_map.win_x + 1;
	e->img->height = e->v_map.win_y + 1;
	e->img->ptr = mlx_new_image(e->mlx, e->img->width, e->img->height);
	e->img->data = mlx_get_data_addr(e->img->ptr, &e->img->bpp,
			&e->img->size_line, &e->img->endian);
}

int				img_pixel_put(t_env *e, int x, int y, int color)
{
	t_img	*img;
	int		octets;
	int		k;

	if (color < 0)
		color = 0;
	else if (color >= 0xffffff)
		color = 0xffffff;
	img = e->img;
	octets = img->bpp / 8;
	k = img->size_line / octets;
	if ((x >= 0 && x < img->width) && (y >= 0 && y < img->height))
		ft_memcpy(&img->data[octets * (x + k * y)], &color, octets);
	else
		return (-1);
	e->img = img;
	return (1);
}
