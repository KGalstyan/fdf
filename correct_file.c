/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:25:50 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/29 15:59:03 by kgalstya         ###   ########.fr       */
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

static int	cost_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != ',')
		len++;
	return (len);
}

static int	checking(char **split_str, int i)
{
	int	j;

	if (cost_len(split_str[i]) > 7)
		return (0);
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
	if (split_str[i][0] == ',')
		return (0);
	return (1);
}

static int	correct_arguments(char *str)
{
	int		i;
	char	**split_str;

	split_str = ft_split(str, ' ');
	i = 0;
	while (split_str && split_str[i])
	{
		if (!checking(split_str, i))
		{
			free_matrix(split_str);
			return (0);
		}
		i++;
	}
	if (i - 1 > 0 && split_str[i - 1][0] == '\n')
		i--;
	free_matrix(split_str);
	return (i);
}

int	correct_file(char *av)
{
	t_a	data;

	if (!correct_file_name(av))
		return (0);
	data.fd = open(av, O_RDONLY);
	if (data.fd == -1)
		return (0);
	data.str = get_next_line(data.fd);
	if (!data.str || line_is_empty(data.str))
		return (free(data.str), get_next_line(-1), 0);
	data.len = correct_arguments(data.str);
	while (data.str)
	{
		data.len_s = correct_arguments(data.str);
		if (data.len_s == 0 || data.len_s != data.len)
		{
			free(data.str);
			return (0);
		}
		free(data.str);
		data.str = get_next_line(data.fd);
	}
	close(data.fd);
	return (1);
}
