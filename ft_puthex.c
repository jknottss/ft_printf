/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:27:32 by                   #+#    #+#             */
/*   Updated: 2021/10/23 11:43:06 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_magic_ft(int big_or_small, int nbsave)
{
	char	res;

	if (big_or_small == 1)
		res = 'A' + nbsave - 10;
	if (big_or_small == 0)
		res = 'a' + nbsave - 10;
	return (res);
}

void	ft_puthex(unsigned long long nb, int *ptr, int big_or_small)
{
	char				res[17];
	unsigned int		nbsave;
	int					i;

	i = 0;
	if (nb == 0)
		ft_putchar('0', ptr);
	nbsave = nb;
	while (nb > 0)
	{
		nbsave = nb % 16;
		if (nbsave >= 0 && nbsave < 10)
			res[i] = nbsave + '0';
		else
			res[i] = ft_magic_ft(big_or_small, nbsave);
		nb /= 16;
		i++;
	}
	res[i] = 0;
	while (--i >= 0)
		ft_putchar(res[i], ptr);
}
