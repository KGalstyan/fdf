/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:26:59 by kgalstya          #+#    #+#             */
/*   Updated: 2024/02/19 17:27:14 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_len(unsigned long n, char x)
{
	int	len;

	len = 0;
	if (n >= 16 && x == 'x')
		len += ft_puthex_len(n / 16, 'x');
	if (n >= 16 && x == 'X')
		len += ft_puthex_len(n / 16, 'X');
	if (x == 'x')
		ft_putchar_len("0123456789abcdef"[n % 16]);
	else
		ft_putchar_len("0123456789ABCDEF"[n % 16]);
	len++;
	return (len);
}

// int	main(void)
// {
// 	int	a;

// 	a = ft_puthex_len(10, 'X');
// 	return(0);
// }