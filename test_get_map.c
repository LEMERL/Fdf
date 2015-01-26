/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/26 12:16:38 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		test_get_map(t_fdf **s)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		printf("Nous sommes ligne %d\n", i);
		while (s[i][j].x >= 0)
		{
			printf("Nous sommes a l'index %d :\n", j);
			printf("Ligne : %d\n", s[i][j].y);
			printf("Hauteur : %d\n", s[i][j].z);
			printf("Colomne : %d\n", s[i][j].x);
			printf("Couleur : %d\n", s[i][j].color);
			printf("aff_x : %d\n", s[i][j].aff_x);
			printf("aff_y : %d\n", s[i][j].aff_y);
			j++;
		}
		j = 0;
		ft_putendl("");
		i++;
	}
}
