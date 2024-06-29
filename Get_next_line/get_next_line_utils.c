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
#include "../fdf.h"

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
	char		*new_str;
	size_t		f_index;
	size_t		s_index;

	if (!s1 || !s2)
		return (NULL);
	if (s2[0] == '\0')
		return (ft_strdup(s1));
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	f_index = 0;
	s_index = 0;
	while (s1 && s1[f_index])
		new_str[s_index++] = s1[f_index++];
	f_index = 0;
	while (s2 && s2[f_index])
		new_str[s_index++] = s2[f_index++];
	new_str[s_index] = '\0';
	return (new_str);
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
