/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:36:22 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/26 18:20:53 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
 ** Transforme un tableau de char contenant des chiffres separes par des espaces
 ** en un tableau d'int.
 */

static size_t		recup_col(char *s, size_t result, int i)
{
	while (s && *s && ft_isdigit(*s) == 1)
		s++;
	if ((i = 0) || (s && s[i]))
		s++;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	if (s && s[i] == '0' && s + 1 && s + 2 && s[i + 1] == 'X')
	{
		s = s + 2;
		while (s[i] != 0 && ((s[i] >= '0' && s[i] <= '9')
				|| (s[i] >= 'A' && s[i] <= 'F')))
			i++;
		while ((--i) >= 0)
		{
			result = result * 16;
			if (s[i] >= '0' && s[i] <= '9')
				result = result + s[i] - '0';
			if (s[i] >= 'A' && s[i] <= 'F')
				result = result + s[i] - 'A' + 10;
		}
	}
	return (result);
}

static void		free_all(char **split, size_t *color)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(color);
}

static void		fill_struct(int y, int x, char *prev_z, t_fdf *res)
{
	t_fdf	str;

	str = *res;
	str.x = x;
	str.y = y;
	str.z = ft_atoi(prev_z);
	str.color = -42;
	str.aff_c = 0;
	str.aff_x = 0;
	str.aff_y = 0;
	*res = str;
}

t_fdf			*ft_strtofdf(const char *s, int line, int i)
{
	t_fdf		*result;
	char		**split;
	int			words;
	size_t		*color;

	color = NULL;
	words = countword(s, ' ');
	result = NULL;
	if ((result = (t_fdf*)ft_memalloc(sizeof(t_fdf) * (words + 1))) == NULL)
		return (NULL);
	if ((color = (size_t*)ft_memalloc(sizeof(size_t) * words))  == NULL)
		return (NULL);
	split = ft_strsplit(s, ' ');
	while (i < words && split[i])
		color[i] = recup_col(split[i], 42, 0);
	i = 0;
	while (i < words && split[i])
	{
		fill_struct(line, i, split[i], result + i);
		i++;
	}
	result[words].x = (-42);
	result[words].y = (-42);
	free_all(split, color);
	return (result);
}
