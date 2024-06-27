/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:31:02 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/27 16:31:11 by kgalstya         ###   ########.fr       */
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
	while (str_spl_line[i])
	{
		j = 0;
		str_spl_args = ft_split(str_spl_line[i], ' ');
		z_values[i] = (int *)malloc(sizeof(int) * (param->len));
		while (str_spl_args[j])
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

void	reading_file(char *av, t_data *param)
{
	int		fd;
	char	*str;
	char	*cur_line;
	char	*tmp;

	str = "";
	param->hight = 0;
	fd = open(av, O_RDONLY);
	while (1)
	{
		cur_line = get_next_line(fd);
		if (!cur_line)
			break ;
		param->len = get_len(cur_line);
		tmp = ft_strjoin(str, cur_line);
		if (str[0] != '\0')
			free(str);
		str = tmp;
		param->hight++;
		free(cur_line);
	}
	param->z_values = get_z_value(str, param);
	free(str);
	close(fd);
}
