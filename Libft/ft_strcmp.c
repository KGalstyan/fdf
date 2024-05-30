/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:17:24 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/01 18:17:24 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int a = ft_strncmp("LondoA", "London", 5);
	printf("%d", a);
	return(0);
}
*/
