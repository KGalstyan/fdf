/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:34:13 by kgalstya          #+#    #+#             */
/*   Updated: 2024/02/21 15:35:13 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int nb)
{
	char	*num;
	int		len;

	num = ft_itoa(nb);
	len = ft_putstr_len(num);
	free (num);
	return (len);
}

/*
int	main(void)
{
	ft_putnbr_len(125);
	return(0);
}
*/
