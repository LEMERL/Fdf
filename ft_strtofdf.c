/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:36:22 by scoudert          #+#    #+#             */
/*   Updated: 2015/02/04 15:30:09 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
 ** Transforme un tableau de char contenant des chiffres separes par des espaces
 ** en un tableau d'int.
 */

static size_t		aux_color(size_t result, char *s, int i)
{
	result = result * 16;
	if (s[i] >= '0' && s[i] <= '9')
		result = result + s[i] - '0';
	if (s[i] >= 'A' && s[i] <= 'F')
		result = result + s[i] - 'A' + 10;
	return (result);
}

static size_t		recup_col(char *s, size_t result, int i, int j)
{
	while (ft_isdigit(s[i]) == 1 && s[i])
		i++;
	if (s && s[i])
		i++;
	j = i + 1;
	while (s[j] != '\0')
	{
		s[j] = ft_toupper(s[j]);
		j++;
	}
	if (s && s[i] == '0' && s + 1 && s + 2 && s[i + 1] == 'X')
	{
		result = 1;
		i += 2;
		while (s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9')
		|| (s[i] >= 'A' && s[i] <= 'F')))
			i++;
		while (i >= j)
		{
			result = aux_color(result, s, i);
			i--;
		}
	}
	return (result - 1);
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

static void		fill_struct(int y, int x, char *prev_z, t_fdf *res, int color)
{
	t_fdf	str;

	str = *res;
	str.x = x;
	str.y = y;
	str.z = ft_atoi(prev_z);
	str.color = color;
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
	{
		color[i] = recup_col(split[i], -41, 0, 0);
		i++;
	}
	i = 0;
	while (i < words && split[i])
	{
		fill_struct(line, i, split[i], result + i, (int)color[i]);
		i++;
	}
	result[words].x = (-42);
	result[words].y = (-42);
	free_all(split, color);
	return (result);
}
