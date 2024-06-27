/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:30:45 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/27 17:22:34 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void z_rotate(t_data_fl *cordfloat, int angle)
// {
//     float tmp_x;
//     float tmp_y;

//     tmp_x = cordfloat->x;
//     tmp_y = cordfloat->y;
//     cordfloat->x = cos(angle) * tmp_x - sin(angle) * tmp_y;
//     cordfloat->y = sin(angle) * tmp_x + cos(angle) * tmp_y;
//     //cordfloat->z = sin(angle) * tmp_x + cos(angle) * tmp_y + tmp_z;
//     //printf("y ============ %f\n", cordfloat.y);
// }

// void x_rotate(t_data_fl *cordfloat, int angle)
// {
//     float tmp_y;
//     float tmp_z;
//     tmp_y = cordfloat->y;
//     tmp_z = cordfloat->z;
//     cordfloat->y = cos(angle) * tmp_y - sin(angle) * tmp_z;
//     cordfloat->z = sin(angle) * tmp_y + cos(angle) * tmp_z;
// }

static void	isometric(t_data_fl *cordfloat)
{
	float	tmp;

	tmp = cordfloat->x;
	cordfloat->x = (tmp - cordfloat->y) * cos(0.523599);
	cordfloat->y = (tmp + cordfloat->y) * sin(0.523599) - cordfloat->z;
}

static void	get_cords(t_point *cord, t_data_fl *cordfloat, t_img *img,
		t_data *param)
{
	cordfloat->x = cord->tmp.x1 * X_GAP;
	cordfloat->y = cord->tmp.y1 * Y_GAP;
	cordfloat->z = param->z_values[cord->tmp.y1][cord->tmp.x1] * Z_GAP;
	isometric(cordfloat);
	cord->x1 = cordfloat->x + param->center_x;
	cord->y1 = cordfloat->y + param->center_y;
	cordfloat->x = cord->tmp.x2 * X_GAP;
	cordfloat->y = cord->tmp.y2 * Y_GAP;
	cordfloat->z = param->z_values[cord->tmp.y2][cord->tmp.x2] * Z_GAP;
	isometric(cordfloat);
	cord->x2 = cordfloat->x + param->center_x;
	cord->y2 = cordfloat->y + param->center_y;
	draw_line(img, cord);
}

static void	draw_y_line(t_point *cord, t_data_fl *cordfloat, t_img *img,
		t_data *param)
{
	cord->tmp.x1 = 0;
	cord->tmp.x2 = 0;
	while (cord->tmp.x2 < param->len)
	{
		cord->tmp.y1 = 0;
		cord->tmp.y2 = 1;
		while (cord->tmp.y2 < param->hight)
		{
			get_cords(cord, cordfloat, img, param);
			cord->tmp.y1++;
			cord->tmp.y2++;
		}
		cord->tmp.x1++;
		cord->tmp.x2++;
	}
}

void	draw_all(t_data *param, t_img *img, t_mlx *mlxparams)
{
	t_point		cord;
	t_data_fl	cordfloat;

	cord.tmp.y1 = 0;
	cord.tmp.y2 = 0;
	while (cord.tmp.y2 < param->hight)
	{
		cord.tmp.x1 = 0;
		cord.tmp.x2 = 1;
		while (cord.tmp.x2 < param->len)
		{
			get_cords(&cord, &cordfloat, img, param);
			cord.tmp.x1++;
			cord.tmp.x2++;
		}
		cord.tmp.y1++;
		cord.tmp.y2++;
	}
	draw_y_line(&cord, &cordfloat, img, param);
	mlx_put_image_to_window(mlxparams->mlx, mlxparams->mlx_win, img->img, 0, 0);
}

// void get_gap(t_data *param)
// {
//     if(param->len > 20 && param->len < 40)
//         param->gap = X_GAP / 2;
//     else if(param->len >= 40 && param->len < 80)
//         param->gap = X_GAP / 3;
//     else if(param->len >= 80 && param->len < 100)
//         param->gap = X_GAP / 4;
//     else if(param->len >= 100 && param->len < 200)
//         param->gap = X_GAP / 5;
//     else if(param->len >= 200 && param->len < 300)
//         param->gap = X_GAP / 10;
//     else if(param->len > 300)
//         param->gap = 1;
// }

void	draw_map(char *av)
{
	t_data	param;
	t_mlx	mlxparams;
	t_img	img;

	mlxparams.mlx = mlx_init();
	mlxparams.mlx_win = mlx_new_window(mlxparams.mlx, 1920, 1080, "MinilibX");
	img.img = mlx_new_image(mlxparams.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.color = 255;
	param.hight = 0;
	reading_file(av, &param);
	param.center_x = ((1920 + param.len - 200) / 2);
	param.center_y = ((1080 + param.hight - 300) / 2);
	draw_all(&param, &img, &mlxparams);
	free_matrix_int(param.z_values, param.hight);
	mlx_hook(mlxparams.mlx_win, KEY_PRESS, KEY_PRESS_MASK, win_hooks,
		&mlxparams);
	mlx_hook(mlxparams.mlx_win, OFF_X, KEY_PRESS_MASK, close_window,
		&mlxparams);
	mlx_loop(mlxparams.mlx);
}
