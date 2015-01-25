/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/25 16:13:09 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/get_next_line.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>

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

t_fdf	**fdf_mapping(int argc, const char *argv[]);
{
	int		fd;
	t_fdf	**s;

	fd = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Map error : Please enter a valid map name", 2);
		exit(0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("Map error : Cannot read or find map", 2);
		exit(0);
	}
	if ((s = get_map(fd)) == NULL)
	{
		ft_putendl_fd("Error : Program abort", 2);
		exit(0);
	}
	return (s);
}

void	ft_double_tab_del(void **tab)
{
	int		j;

	j = 0;
	if (tab)
	{
		while (tab[j] != NULL)
		{
			free(tab[j]);
			j++;
		}
	}
	free(tab);
}

void	fdf_use_tab(t_fdf **s, t_env *env)
{
	int		i;
	int		j;
	int		c1;
	int		c2;
	int		cst

	c1 = 75;
	c2 = 75;
	cst = 80;
	i = 0;
	while ((j = 0) && s[i] && (i++))
		while (s[i][j].x >= 0)
		{
			if (ISO == 1)
				fdf_proj_iso(s[i][j], c1, c2, env);
			else
				fdf_proj_paral(s[i][j], cst, env);
			j++;
		}
	i = 0;
	while ((j = 0) && s[i] && (i++))
		while (s[i][j].x >= 0 && (k = 0))
		{
			if (s[i][j + 1].x >= 0)
				ft_trace_segm(s[i][j], s[i][j], env);
			while (s[i + 1] && s[i][k].x >= 0 && (k != j + 1))
			{
				if (k == j)
					ft_trace_segm(s[i][j], s[i + 1][j], env);
				k++;
			}
			j++;
		}
}
