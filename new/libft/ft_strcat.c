/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:23:23 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/18 17:45:31 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *dest, char *src)
{
	size_t		i;
	int			len;

	i = 0;
	len = ft_strlen(dest);
	while (i < (ft_strlen(src) + ft_strlen(dest)))
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	return (dest);
}
