#include "ft_printf.h"

static int	ft_printf2(char s, va_list args, size_t j)
{
	if (s == 'd' || s == 'i')
		j = ft_cint(va_arg(args, int));
	else if (s == 'c')
		j = ft_putchar(va_arg(args, int));
	else if (s == 's')
		j = ft_putstr(va_arg(args, char *));
	else if (s == 'u')
		j = ft_llu(va_arg(args, unsigned int));
	else if (s == 'p')
		j = ft_voidx0(va_arg(args, unsigned long long));
	else if (s == 'x')
		j = ft_putlew(va_arg(args, unsigned int));
	else if (s == 'X')
		j = ft_putup(va_arg(args, unsigned int));
	else
		j = ft_putchar(s);
	return (j);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	size_t	j;

	va_start(args, s);
	i = 0;
	j = 0;
	if (write(1, "0", 0) == -1)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			j += ft_printf2(s[i], args, j);
		}
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (j);
}
