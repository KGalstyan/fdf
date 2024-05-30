/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:05:00 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/30 16:00:27 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;
	int		mem;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	mem = ft_strlen(s + start);
	if (len < mem)
		mem = len;
	str = (char *)malloc((mem + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len && !(start > ft_strlen(s)))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
