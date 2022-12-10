/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:27:38 by osabir            #+#    #+#             */
/*   Updated: 2022/12/05 14:16:24 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putup(unsigned long n)
{
	int	i;

	i = 0;
	if (n > 15)
	{
		ft_putup(n / 16);
		ft_putup(n % 16);
	}
	else
		ft_putchar("0123456789ABCDEF"[n]);
	return (ft_len(n));
}
