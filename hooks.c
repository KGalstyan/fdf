/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:36:30 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/27 14:38:39 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_hooks(int keycode, t_mlx *mlxparams)
{
	if (keycode == OFF_ESC)
	{
		mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
		mlx_destroy_window(mlxparams->mlx, mlxparams->mlx_win);
		system("leaks fdf");
		exit(0);
	}
	return (0);
}

int	close_window(t_mlx *mlxparams)
{
	mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
	mlx_destroy_window(mlxparams->mlx, mlxparams->mlx_win);
	system("leaks fdf");
	exit(0);
	return (0);
}

// void hooks_management(int keycode, t_mlx *mlxparams)
// {
//     if(keycode == KEY_PRESS_Z)
//     {
//         mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
//         mlxparams->angle_z += 20;
//     }
//     if(keycode == KEY_PRESS_X)
//     {
//         mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
//         mlxparams->angle_x += 20;
//     }
//     if(keycode == KEY_PRESS_Y)
//     {
//         mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
//         mlxparams->angle_y += 20;
//     }
// }