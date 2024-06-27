/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:27:52 by kgalstya          #+#    #+#             */
/*   Updated: 2024/02/19 17:27:56 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	alo(unsigned long long p)
{
	int	len;

	len = 0;
	if (p >= 16)
		len += alo(p / 16);
	len += ft_putchar_len("0123456789abcdef"[p % 16]);
	return (len);
}

int	ft_putptr_len(unsigned long long p)
{
	int	len;

	len = 0;
	len += ft_putstr_len("0x");
	len += alo(p);
	return (len);
}

// int main()
// {
// 	int a;

// 	a = 0;
// 	ft_putptr_len(1555);
// 	printf("\n%p\n", 1555);
// 	return(0);
// }
