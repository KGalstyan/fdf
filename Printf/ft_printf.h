/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:35:30 by kgalstya          #+#    #+#             */
/*   Updated: 2024/02/21 15:36:58 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putunsigned_len(unsigned int nb);
int		ft_putstr_len(char *s);
int		ft_putptr_len(unsigned long long p);
int		ft_putnbr_len(int nb);
int		ft_puthex_len(unsigned long n, char x);
int		ft_putchar_len(char c);
char	*ft_itoa(int n);

#endif
