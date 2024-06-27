/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:34:31 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/27 16:06:37 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!correct_file(argv[1]))
		{
			printf("Something wrong with file !?\n");
			system("leaks fdf");
			exit(1);
		}
		else
			draw_map(argv[1]);
	}
	else
		printf("please enter file name\n");
	return (0);
}
