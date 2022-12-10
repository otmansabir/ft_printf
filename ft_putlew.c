/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:50:29 by osabir            #+#    #+#             */
/*   Updated: 2022/12/05 14:19:33 by osabir           ###   ########.fr       */
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

int	ft_putlew(unsigned long n)
{
	if (n > 15)
	{
		ft_putlew(n / 16);
		ft_putlew(n % 16);
	}
	else
		ft_putchar("0123456789abcdef"[n]);
	return (ft_len(n));
}
