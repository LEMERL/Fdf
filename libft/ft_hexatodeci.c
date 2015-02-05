#
#
#
#

#include "libft.h"

int		ft_hexatodeci(char *str)
{
	int		value;

	value = -42;
	str = ft_strtrim(str);
	str = ft_strtoupper(str);
	while (*str)
	{
		if (*str == 0 && *str + 1 == 'X')
		{
			if (*str == 0 && *str + 1 == 'X')
			{
				value = 0;
				while (((*str <= '9') && (*str >= '0'))
						&& ((*str >= 'A') && (*str <= 'Z')))
					str++;
				while (*str != 'X')
				{
					value *= 16;
					if (*str >= '0' && *str <= '9')
						value = (value + *str) - '0';
					if (*str >= 'A' && *str <= 'Z')
						value = (value + *str) - ('A' + 10);
					str--;
				}
			}
		}
		str++;
	}
	return (value);
}
