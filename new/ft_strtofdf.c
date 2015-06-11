/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:36:22 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/11 20:55:45 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Transforme un tableau de char contenant des chiffres separes par des espaces
** en un tableau d'int.
*/

static void		clear_all(char **split, t_fdf *result, int words)
{
	int			i;

	i = 0;
	result[words].x = (-42);
	result[words].y = (-42);
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

static void		fill_struct(int y, int x, char *prev_z, t_fdf *res)
{
	t_fdf		str;

	str = *res;
	str.x = x;
	str.y = y;
	if (ft_atoi_1(prev_z) == -1 && ft_atoi_2(prev_z) == 1)
	{
		ft_putstr_fd("Value: \033[31m", 2);
		ft_putstr_fd(prev_z, 2);
		ft_putendl_fd("\033[0m cannot be stocked in an integer", 2);
		exit(1);
	}
	str.z = ft_atoi(prev_z);
	while (*prev_z != '\0' && *prev_z != ',')
		prev_z++;
	str.color = -1;
	if (*prev_z == ',')
	{
		str.color = ft_hexatodeci(prev_z + 1);
		ft_putnbr(str.color);
		ft_putendl("");
	}
	str.print_x = 0;
	str.print_y = 0;
	*res = str;
}

int				test_wrong_value(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '-' && s[i] != ',' &&
			(s[i] != '0' && (s[i + 1] != 'X' || s[i + 1] != 'x')) &&
			((s[i] != 'x' || s[i] != 'X') && s[i - 1] != '0')
			&& ft_hexatodeci(s) == -42)
		{
			ft_putstr_fd("Error : Wrong value \"\033[31m", 2);
			ft_putchar_fd(s[i], 2);
			ft_putendl_fd("\033[0m\" in map. Program abort.", 2);
			exit(-1);
		}
		i++;
	}
	return (0);
}

t_fdf			*ft_strtofdf(const char *s, int line, int i)
{
	t_fdf		*result;
	char		**split;
	int			words;

	words = countword(s, ' ');
	if ((result = (t_fdf*)ft_memalloc(sizeof(t_fdf) * (words + 1))) == NULL)
		return (NULL);
	split = ft_strsplit(s, ' ');
	while (i < words && split[i])
		test_wrong_value(split[i++]);
	i = 0;
	while (i < words && split[i])
	{
		fill_struct(line, i, split[i], result + i);
		i++;
	}
	clear_all(split, result, words);
	return (result);
}
