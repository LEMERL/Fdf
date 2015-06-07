/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/07 00:55:09 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		test_get_map(t_fdf **s, t_env *e)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		printf("Nous sommes ligne %d\n", s[i][j].y);
		while (s[i][j].x >= 0)
		{
			printf("Nous sommes a l'index %d :\n", s[i][j].x);
			printf("print_x: %d\n", s[i][j].print_x);
			printf("print_y: %d\n", s[i][j].print_y);
			printf("paral_y: %d\n", s[i][j].paral_x);
			printf("paral_x: %d\n", s[i][j].paral_y);
			printf("iso_x:   %d\n", s[i][j].iso_x);
			printf("iso_y:   %d\n", s[i][j].iso_y);
			j++;
		}
		j = 0;
		ft_putendl("");
		i++;
	}
		if (e != NULL)
		{
			printf("ecart : %d\n", e->v_map.ecart);
			printf("img_x : %d\n", e->v_map.img_x);
			printf("img_y : %d\n", e->v_map.img_y);
			printf("ecart : %d\n", e->v_map.ecart);
		ft_putendl("");
		}
}
