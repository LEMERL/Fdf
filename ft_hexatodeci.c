#
#
#
#

#include "libft.h"

int		ft_haxatodeci(char const *str)
{
	int		is_negative;
	int		value;

	is_negative = 0;
	value = 0;
	str = ft_strtrim(str);
	while (ft_isdigit(*str) != 0)
		s++;
	if (*s == 0 && (*s + 1 == 'x' || *s + 1 == 'X'))
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	if (!is_negative)
		value *= -1;
	return (value);
}
