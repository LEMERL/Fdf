#
#
#
#

#include "includes/libft.h"

int		ft_hexatodeci(char *str)
{
	int		value;
	char	*ptr;
	char	*p;

	value = -42;
	ptr = ft_strtrim(str);
	p = ptr;
	while (*ptr)
	{
		if (*(ptr++) == '0')
		{
			if (*ptr == 'X' || *ptr == 'x')
			{
				ptr++;
				value = 0;
				while (((*ptr <= '9') && (*ptr >= '0'))
						|| ((*ptr >= 'A') && (*ptr <= 'Z'))
						|| ((*ptr >= 'a') && (*ptr <= 'z')))
				{
					value = value * 16;
					if (*ptr >= '0' && *ptr <= '9')
						value = (value + *ptr) - '0';
					if (*ptr >= 'A' && *ptr <= 'Z')
						value = ((value + *ptr) - 'A') + 10;
					if (*ptr >= 'a' && *ptr <= 'z')
						value = ((value + *ptr) - 'a') + 10;
					ptr++;
				}
				free(p);
				return (value);
			}
			else
				ptr++;
		}
	}
	free(p);
	return (value);
}
