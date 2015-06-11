/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:24:26 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 13:16:55 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		i;

	i = ft_strlen(s);
	newstr = ft_strnew(i * sizeof(char));
	if (newstr == NULL)
	{
		return (NULL);
	}
	ft_strcpy(newstr, s);
	return (newstr);
}
