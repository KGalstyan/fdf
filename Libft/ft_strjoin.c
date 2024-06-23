// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_strjoin.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/05 20:34:10 by kgalstya          #+#    #+#             */
// /*   Updated: 2024/02/06 16:03:30 by kgalstya         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fdf.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	int		n;
// 	char	*res;

// 	if (!s1)
// 		return (NULL);
// 	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	n = 0;
// 	while (s1[i] != '\0')
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[n] != '\0')
// 	{
// 		res[i] = s2[n];
// 		n++;
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }
