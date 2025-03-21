#include "ft_printf.h"

static int	ft_clen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_llu(unsigned int n)
{
	if (n > 9)
	{
		ft_llu(n / 10);
		ft_llu(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (ft_clen(n));
}
