/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidx0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:56:34 by osabir            #+#    #+#             */
/*   Updated: 2022/12/05 13:57:25 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long n)
{
	int	i;

	i = 2;
	if (n == 0)
		return (3);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static	int	ft_puthex(unsigned long n)
{
	if (n > 15)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else
		ft_putchar("0123456789abcdef"[n]);
	return (ft_len(n));
}

int	ft_voidx0(unsigned long n)
{
	write(1, "0x", 2);
	return (ft_puthex(n));
}
