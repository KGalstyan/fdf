/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:25:50 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/27 16:25:51 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	correct_file_name(char *av)
{
	int	len;

	len = 0;
	len = ft_strlen(av) - 4;
	if (av[0] != '.' && (ft_strcmp(".fdf", av + len) == 0))
		return (1);
	return (0);
}

static int	checking(char **split_str, int i)
{
	int	j;

	if ((ft_atoi(split_str[i]) > 100000) || (ft_atoi(split_str[i]) < -100000))
		return (0);
	j = 0;
	while (split_str[i][j] != '\n' && split_str[i][j] != '\0'
		&& split_str[i][j] != ',')
	{
		if (split_str[i][j] == '-' && is_digit(split_str[i][j + 1]))
			j++;
		else if (!(is_digit(split_str[i][j])))
			return (0);
		j++;
	}
	return (1);
}

static int	correct_arguments(char *str)
{
	int		i;
	char	**split_str;

	split_str = ft_split(str, ' ');
	i = 0;
	while (split_str[i])
	{
		if (!checking(split_str, i))
		{
			free_matrix(split_str);
			return (0);
		}
		i++;
	}
	if (split_str[i - 1][0] == '\n')
		i--;
	free_matrix(split_str);
	return (i);
}

int	correct_file(char *av)
{
	int		fd;
	char	*str;
	int		len;

	if (!correct_file_name(av))
		return (0);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	if (!str)
		return (0);
	len = correct_arguments(str);
	while (str)
	{
		if (correct_arguments(str) == 0 || correct_arguments(str) != len)
		{
			free(str);
			return (0);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (1);
}
