/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:34:31 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/29 15:59:47 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!correct_file(argv[1]))
		{
			ft_printf("Something wrong with file !?\n");
			exit(1);
		}
		else
			draw_map(argv[1]);
	}
	else
		ft_printf("please enter file name\n");
	return (0);
}
