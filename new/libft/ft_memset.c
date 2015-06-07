/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:21:37 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/13 18:08:05 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = b;
	if (len && b)
	{
		while (i < len)
		{
			dst[i] = c;
			i++;
		}
	}
	return (b);
}
