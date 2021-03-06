/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:37:21 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/13 17:50:54 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
