#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	}
	return (i);
}
