/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_tab_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:57:50 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 21:57:52 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	ft_double_tab_del(void **tab)
{
	int	j;

	j = 0;
	if (tab)
	{
		while (tab[j] != NULL)
		{
			free(tab[j]);
			j++;
		}
	}
	free(tab);
}
