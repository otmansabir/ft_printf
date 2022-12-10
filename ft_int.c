/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:10 by osabir            #+#    #+#             */
/*   Updated: 2022/11/29 16:19:22 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_clen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_cint(int n)
{
	int	j;

	j = n;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		ft_cint(n);
	}
	else if (n > 9)
	{
		ft_cint(n / 10);
		ft_cint(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (ft_clen(j));
}
