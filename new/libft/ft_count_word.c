/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 22:05:04 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 22:05:07 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Count words in the string 's' who are seperated by the char 'sep'
** like in the ft_strsplit function.
*/
#include "includes/libft.h"

unsigned int	countword(const char *s, char sep)
{
	int				i;
	unsigned int	counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
			counter++;
		i++;
	}
	return (counter);
}
