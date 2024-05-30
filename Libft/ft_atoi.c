/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:28:49 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/30 15:59:57 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

long long	ft_atoi(const char *nptr)
{
	long long	num;
	int			sign;
	int			n;

	n = 0;
	sign = 1;
	num = 0;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == ' ')
	{
		n++;
	}
	if (nptr[n] == '-' || nptr[n] == '+')
	{
		if (nptr[n] == '-')
		{
			sign *= -1;
		}
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		num = num * 10 + (nptr[n] - '0');
		n++;
	}
	return (num * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_atoi(""));
	return(0);
}
*/
