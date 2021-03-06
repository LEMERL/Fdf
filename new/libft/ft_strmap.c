/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:20:36 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/13 17:24:11 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*newstr;

	newstr = NULL;
	i = 0;
	if (s && (*f))
	{
		size = ft_strlen(s);
		newstr = malloc(size + 1);
		if (newstr == NULL)
			return (NULL);
		newstr[size] = '\0';
		while (i < size)
		{
			newstr[i] = (*f)(s[i]);
			i++;
		}
		return (newstr);
	}
	return (0);
}
