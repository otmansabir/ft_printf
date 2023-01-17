#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *s, ...);
int				ft_cint(int n);
int				ft_llu(unsigned int n);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putup(unsigned long n);
int				ft_putlew(unsigned long n);
int				ft_voidx0(unsigned long n);

#endif
