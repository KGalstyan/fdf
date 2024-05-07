/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:50:53 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/07 15:47:01 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	while (s[i])
	{
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		str[n] = s[n];
		n++;
	}
	str[i] = 0;
	return (str);
}
