/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:31:02 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/29 15:36:39 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**get_z_value(char *str, t_data *param)
{
	char	**str_spl_line;
	char	**str_spl_args;
	int		**z_values;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_spl_line = ft_split(str, '\n');
	z_values = (int **)malloc(sizeof(int *) * (param->hight));
	while (i < param->hight)
	{
		j = 0;
		str_spl_args = ft_split(str_spl_line[i], ' ');
		z_values[i] = (int *)malloc(sizeof(int) * (param->len));
		while (j < param->len)
		{
			z_values[i][j] = ft_atoi(str_spl_args[j]);
			j++;
		}
		free_matrix(str_spl_args);
		i++;
	}
	free_matrix(str_spl_line);
	return (z_values);
}

int	get_len(char *str)
{
	int		len;
	char	**split_str;

	split_str = ft_split(str, ' ');
	len = 0;
	while (split_str[len] && split_str[len][0] != '\n')
		len++;
	free_matrix(split_str);
	return (len);
}

int	line_is_empty(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (is_digit(str[i]))
			n++;
		i++;
	}
	if (i == 0 || n == 0)
		return (1);
	return (0);
}

void	reading_file(char *av, t_data *param)
{
	int		fd;
	char	*str;
	char	*cur_line;
	char	*tmp;

	str = "";
	fd = open(av, O_RDONLY);
	while (1)
	{
		cur_line = get_next_line(fd);
		if (!cur_line || line_is_empty(cur_line))
			break ;
		param->len = get_len(cur_line);
		tmp = ft_strjoin(str, cur_line);
		if (str[0] != '\0')
			free(str);
		str = tmp;
		param->hight++;
		free(cur_line);
	}
	if (cur_line && line_is_empty(cur_line))
		free(cur_line);
	param->z_values = get_z_value(str, param);
	free(str);
	close(fd);
}
