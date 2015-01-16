/  ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillau <mguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:53:28 by mguillau          #+#    #+#             */
/*   Updated: 2015/01/07 18:49:20 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_set_map(int fd)
{
	char	*line;
	int		**map;
	char	**array;
	t_lst	*lst;
	t_lst	**alst;
	int		i;

	i = 0;
	line = NULL;
	alst = &line;
	while (get_next_line(fd, &line) > 0)
	{
		array = ft_strsplit(line, ' ');
		lst = ft_lstnew(NULL, 0);
		lst->content = array;
		lst->content_size = ft_count_word(line, ' ');
		ft_machin_iter(lst->content, atoi());
		ft_lstadd(alst, lst);
	}
	lst = *alst;
	map = malloc(sizeof(int*) * (ft_count_maillon(alst) + 1));
	while (lst != NULL)
	{
		map[i] = lst->content;
		i++;
		lst = lst->next;
		map[i] = NULL;
	}
	ft_lstdel(alst);
	return (map);
}
