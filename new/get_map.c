/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 21:44:34 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/12 09:36:20 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>

/*
** Transforme le fichier recu en parametre par file descriptor en int **tab
*/

t_fdf		**fdf_mapping(int argc, const char *argv[])
{
	int		fd;
	t_fdf	**s;

	fd = 0;
	if ((fd = open(argv[argc - 1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("Map error : Cannot read or find map", 2);
		ft_wait_exit(0);
	}
	if ((s = get_map(fd, 0)) == NULL)
	{
		ft_putendl_fd("Error : Program abort", 2);
		ft_wait_exit(0);
	}
	if (s == NULL || *s == NULL)
	{
		ft_putendl_fd("Error : Empty map", 2);
		ft_wait_exit(0);
	}
	return (s);
}

t_fdf		**get_map(int fd, int j)
{
	char	*map;
	t_list	*array;
	t_fdf	**res;
	t_list	*ptr_array;

	array = NULL;
	while (get_next_line(fd, &map) > 0)
	{
		if (map[0] != '\0')
			ft_lstaddend(map, ft_strlen(map), &array);
		free(map);
	}
	ptr_array = array;
	res = (t_fdf**)ft_memalloc(sizeof(t_fdf*) * (countelem(array) + 1));
	while (array != NULL)
	{
		if ((res[j] = ft_strtofdf(array->content, j, 0)) == NULL)
			return (NULL);
		array = array->next;
		j++;
	}
	res[j] = NULL;
	ft_lstdel(&ptr_array, del);
	return (res);
}
