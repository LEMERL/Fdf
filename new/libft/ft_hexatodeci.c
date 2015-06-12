/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatodeci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:56:28 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/12 12:22:21 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	calc_hexa(char *ptr, int value, char *t)
{
	ptr++;
	while (((*ptr <= '9') && (*ptr >= '0'))
			|| ((*ptr >= 'A') && (*ptr <= 'Z'))
			|| ((*ptr >= 'a') && (*ptr <= 'z')))
	{
		value = value * 16;
		if (*ptr >= '0' && *ptr <= '9')
			value = (value + *ptr) - '0';
		if (*ptr >= 'A' && *ptr <= 'Z')
			value = ((value + *ptr) - 'A') + 10;
		if (*ptr >= 'a' && *ptr <= 'z')
			value = ((value + *ptr) - 'a') + 10;
		ptr++;
	}
	free(t);
	return (value);
}

int			ft_hexatodeci(char *str)
{
	char	*ptr;
	char	*p;

	ptr = ft_strtrim(str);
	p = ptr;
	while (*ptr)
	{
		if (*(ptr++) == '0')
		{
			if (*ptr == 'X' || *ptr == 'x')
				return (calc_hexa(ptr, 0, p));
			else
				ptr++;
		}
	}
	free(p);
	return (-42);
}
