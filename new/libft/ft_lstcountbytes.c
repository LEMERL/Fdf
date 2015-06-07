/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcountbytes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:31:52 by mgrimald          #+#    #+#             */
/*   Updated: 2014/12/08 13:31:54 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_lstcountbytes(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i += (int)(lst->content_size);
		lst = lst->next;
	}
	return (i);
}
