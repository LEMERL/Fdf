/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 17:51:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/11 17:51:07 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <limits.h>

int			check_int(int i, char c, int sign)
{
	if (i > INT_MAX / 10 || (i == INT_MAX / 10 && (c == '9' ||
					(c == '8' && sign == 0))))
		return (-1);
	return (0);
}

int			ft_atoi_1(const char *str)
{
	int		sign;
	int		val;
	int		i;

	i = 0;
	sign = 0;
	val = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_int(val, str[i], sign))
			return (-1);
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return ((sign == 1) ? -val : val);
}

int			ft_atoi_2(const char *str)
{
	int		sign;
	int		val;
	int		i;

	i = 0;
	sign = 0;
	val = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_int(val, str[i], sign))
			return (1);
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return ((sign == 1) ? -val : val);
}
