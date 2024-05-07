/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:20:18 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/01 18:20:18 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		res[i] = s2[n];
		n++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_free(char *buffer, char *str)
{
	char	*res;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	res = ft_strjoin(buffer, str);
	free(buffer);
	return (res);
}
