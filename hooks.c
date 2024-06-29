/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:36:30 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/29 15:59:55 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_hooks(int keycode, t_mlx *mlxparams)
{
	if (keycode == OFF_ESC)
	{
		mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
		mlx_destroy_window(mlxparams->mlx, mlxparams->mlx_win);
		exit(0);
	}
	return (0);
}

int	close_window(t_mlx *mlxparams)
{
	mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
	mlx_destroy_window(mlxparams->mlx, mlxparams->mlx_win);
	exit(0);
	return (0);
}
