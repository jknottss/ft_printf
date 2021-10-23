/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:05:01 by                   #+#    #+#             */
/*   Updated: 2021/10/21 20:30:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *ptr);
void	ft_putstr(char *str, int *ptr);
void	ft_putunnbr(unsigned int nb, int *ptr);
void	ft_putnbr(int nb, int *ptr);
void	ft_puthex(unsigned long long nb, int *ptr, int big_or_small);

#endif
