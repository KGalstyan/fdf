#include "fdf.h"

void z_rotate(t_data_fl *cordfloat, int angle)
{
    float tmp_x;
    float tmp_y;
    float tmp_z;
    tmp_x = cordfloat->x;
    tmp_y = cordfloat->y;
    tmp_z = cordfloat->z;
    cordfloat->x = cos(angle) * tmp_x - sin(angle) * tmp_y;
    //printf("x == %f\n", cordfloat.x);
    cordfloat->y = sin(angle) * tmp_x + cos(angle) * tmp_y;
    cordfloat->z = sin(angle) * tmp_x + cos(angle) * tmp_y + tmp_z;
    //printf("y ============ %f\n", cordfloat.y);
}

void x_rotate(t_data_fl *cordfloat, int angle)
{
    float tmp_y;
    float tmp_z;
    tmp_y = cordfloat->y;
    tmp_z = cordfloat->z;
    cordfloat->y = cos(angle) * tmp_y - sin(angle) * tmp_z;
    cordfloat->z = sin(angle) * tmp_y + cos(angle) * tmp_z;
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
            cordfloat.x = x1 * X_GAP;
	        cordfloat.y = y1 * Y_GAP;
            cordfloat.z = param->z_values[y1][x1];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x1 = cordfloat.x + 350;   
	        cord.y1 = cordfloat.y + 200 + cordfloat.z;
            // isometric(value);
            //z_rotate(cord.x1, cord.y1, 10, 10);
            cordfloat.x = x2 * X_GAP;
	        cordfloat.y = y2 * Y_GAP;
            cordfloat.z = param->z_values[y2][x2];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x2 = cordfloat.x + 350;   
	        cord.y2 = cordfloat.y + 200 + cordfloat.z;
            // isometric(cord.x2, cord.y2, z2);
            //z_rotate(cord.x1, cord.y1, 10, 10);
            draw_line(img, &cord);
            mlx_put_image_to_window(mlxparams->mlx, mlxparams->mlx_win, img->img, 0, 0);
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
	        cordfloat.x = x1 * X_GAP;
	        cordfloat.y = y1 * Y_GAP;
            cordfloat.z = param->z_values[y1][x1];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x1 = cordfloat.x + 350;   
	        cord.y1 = cordfloat.y + 200 + cordfloat.z;
            printf("x1=%f\n", cordfloat.x);
            printf("y1=%f\n", cordfloat.y);
            //isometric(cord.x1, cord.y1, z1);
            //z_rotate(cord.x1, cord.y1, 10, 10);
            cordfloat.x = x2 * X_GAP;
	        cordfloat.y = y2 * Y_GAP;
            cordfloat.z = param->z_values[y2][x2];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x2 = cordfloat.x + 350;   
	        cord.y2 = cordfloat.y + 200 + cordfloat.z;
            printf("x2=%f\n", cordfloat.x);
            printf("y2=%f\n", cordfloat.y);
            // isometric(cord.x2, cord.y2, z2);
            // z_rotate(cord.x2, cord.y2, 10, 10);
            draw_line(img, &cord);
            mlx_put_image_to_window(mlxparams->mlx, mlxparams->mlx_win, img->img, 0, 0);
            y1++;
            y2++;
        }
        x1++;
        x2++;
    }
}


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
    draw_all(&param, &img, &mlxparams);
    free_matrix_int(param.z_values, param.hight);
    mlx_loop(mlxparams.mlx);
}



