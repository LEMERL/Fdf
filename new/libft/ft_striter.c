/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:59:16 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/13 17:25:37 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	i = 0;
	if (s != NULL && (*f) != NULL)
	{
		while (s[i])
		{
			(*f)(s + i);
			i++;
		}
	}
}
