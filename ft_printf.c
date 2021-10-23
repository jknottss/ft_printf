/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:44:07 by                   #+#    #+#             */
/*   Updated: 2021/10/21 20:35:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_distrub(char c, va_list *lst, int *ptr)
{
	if (c == 'c')
		ft_putchar((char) va_arg(*lst, int), ptr);
	if (c == 's')
		ft_putstr(va_arg(*lst, char *), ptr);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*lst, int), ptr);
	if (c == 'u')
		ft_putunnbr(va_arg(*lst, unsigned int), ptr);
	if (c == '%')
		ft_putchar('%', ptr);
	if (c == 'x')
		ft_puthex(va_arg(*lst, unsigned int), ptr, 0);
	if (c == 'X')
		ft_puthex(va_arg(*lst, unsigned int), ptr, 1);
	if (c == 'p')
	{
		ft_putstr("0x", ptr);
		ft_puthex((unsigned long long) va_arg(*lst, void *), ptr, 0);
	}
}

int	ft_printf(const char *s, ...)
{
	int			i;
	va_list		lst;
	int			res;
	int			*ptr;

	res = 0;
	ptr = &res;
	res = 0;
	i = -1;
	va_start(lst, s);
	while (s[++i])
	{
		if (s[i] == '%')
			ft_distrub(s[++i], &lst, ptr);
		else
			ft_putchar(s[i], ptr);
	}
	va_end(lst);
	return (res);
}
