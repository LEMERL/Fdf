/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:41:10 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/13 17:22:53 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = NULL;
	ptr = ft_memalloc(size + 1);
	if (size + 1)
	{
		if (ptr == NULL)
			return (NULL);
		else
			ft_bzero(ptr, size + 1);
	}
	return (ptr);
}
