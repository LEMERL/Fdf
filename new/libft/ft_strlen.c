/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:35:36 by mgrimald          #+#    #+#             */
/*   Updated: 2014/12/08 10:55:46 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (i);
}
