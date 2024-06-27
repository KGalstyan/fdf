/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:30:45 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/27 16:46:36 by kgalstya         ###   ########.fr       */
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

void  isometric(t_data_fl *cordfloat)
{
    float tmp;

    tmp = cordfloat->x;
    cordfloat->x = (tmp - cordfloat->y) * cos(0.523599);
    cordfloat->y = (tmp + cordfloat->y) * sin(0.523599) - cordfloat->z;
}

void draw_all(t_data *param, t_img *img, t_mlx *mlxparams)
{
    int x1,x2,y1,y2;
    t_point	cord;
    t_data_fl cordfloat;
	y1 = 0;
    y2 = 0;
    while(y2 < param->hight)
    {
        x1 = 0;
        x2 = 1;
        while(x2 < param->len)
        {
            ///////////////////////////////////////////   1
            cordfloat.x = x1 * X_GAP;
	        cordfloat.y = y1 * Y_GAP;
            cordfloat.z = param->z_values[y1][x1] * Z_GAP;
            isometric(&cordfloat);
            cord.x1 = cordfloat.x + param->center_x;   
	        cord.y1 = cordfloat.y + param->center_y;
            /////////////////////////////////////////   2
            cordfloat.x = x2 * X_GAP;
	        cordfloat.y = y2 * Y_GAP;
            cordfloat.z = param->z_values[y2][x2] * Z_GAP;
            isometric(&cordfloat);
            cord.x2 = cordfloat.x + param->center_x;   
	        cord.y2 = cordfloat.y + param->center_y;
            draw_line(img, &cord);
            x1++;
            x2++;
        }
        y1++;
        y2++;
    }

    ////////////////////////////////////////////////////////////////////////////////

    x1 = 0;
    x2 = 0;
    while(x2 < param->len)
    {
        y1 = 0;
        y2 = 1;
        while(y2 < param->hight)
        {
            /////////////////////////////////////////////////////   1
	        cordfloat.x = x1 * X_GAP;
	        cordfloat.y = y1 *  Y_GAP;
            cordfloat.z = param->z_values[y1][x1] * Z_GAP;
            isometric(&cordfloat);
            cord.x1 = cordfloat.x + param->center_x;   
	        cord.y1 = cordfloat.y + param->center_y;
            ///////////////////////////////////////////////////  2
            cordfloat.x = x2 * X_GAP;
	        cordfloat.y = y2 * Y_GAP;
            cordfloat.z = param->z_values[y2][x2] * Z_GAP;
            isometric(&cordfloat);
            cord.x2 = cordfloat.x + param->center_x;   
	        cord.y2 = cordfloat.y + param->center_y;
            draw_line(img, &cord);
            y1++;
            y2++;
        }
        x1++;
        x2++;
    }
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


void    draw_map(char *av)
{
    t_data param;
    t_mlx mlxparams;
	t_img	img;

	mlxparams.mlx = mlx_init();
	mlxparams.mlx_win = mlx_new_window(mlxparams.mlx, 1920, 1080, "MinilibX");
	img.img = mlx_new_image(mlxparams.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.color = 255;
    param.hight = 0;
    reading_file(av, &param);
    param.center_x = ((1920 + param.len - 200) / 2);
    param.center_y = ((1080 + param.hight - 300) / 2);
    //get_gap(&param);
    //mlx_hook(mlxparams.mlx_win, KEY_PRESS, KEY_PRESS_MASK, win_hooks, &mlxparams);
    draw_all(&param, &img, &mlxparams);
    free_matrix_int(param.z_values, param.hight);
    mlx_hook(mlxparams.mlx_win, KEY_PRESS, KEY_PRESS_MASK, win_hooks, &mlxparams);
    mlx_hook(mlxparams.mlx_win, OFF_X, KEY_PRESS_MASK, close_window, &mlxparams);
    mlx_loop(mlxparams.mlx);
}



