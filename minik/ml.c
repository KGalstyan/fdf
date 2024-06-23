#include "minik.h"


void    mlx_pixel_put_img(t_img *img, int x, int y, int color)
{
    char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	is_steep(int dy, int dx);
// {
//     return (dy > dx);
// }

// void  isometric()
// {
//     int tmp;

//     tmp = x;
//     x = (tmp - y) * cos(value.angle);
//     y = (tmp + y) * sin(value.angle) - z;
// }

void draw_line(t_img *img, t_data cord) 
{
    int tx = cord.x2 - cord.x1;
    int ty = cord.y2 - cord.y1;
    int dx = abs(cord.x2 - cord.x1);
    int dy = abs(cord.y2 - cord.y1);
    int p = 2 * dy - dx;
    int x = cord.x1, y = cord.y1;
	int i = 0;

    // t_point point;
	if(dx > dy)
    {
        i = -1;
        while(++i < dx)
        {
            if(tx > 0)
                x++;
            else
                x--;
            if(p < 0)
              p = p + (2 * dy);
            else
            {
                p = p + (2 * dy) - (2 * dx);
                if(ty > 0)
                    y++;
                else
                    y--;
            }
            mlx_pixel_put_img(img, x, y, img->color);
        }
    }

    else
    {
        p = 2 * tx - ty;
        i = 0;
        mlx_pixel_put_img(img, x, y, img->color);
        while(i < dy)
        {
            if(ty > 0)
                y++;
            else
                y--;
            if(p < 0 && tx >= 0)
              p = p + (2 * tx);
            else
            {
                if(tx > 0)
                    x++;
                else
                    x--;
                p = p + (2 * tx) - (2 * ty);
            }
            mlx_pixel_put_img(img, x, y, img->color);
            i++;
        }
    }
}

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

void y_rotate(t_data_fl *cordfloat, int angle)
{
    float tmp_x;
    float tmp_z;

    tmp_x = cordfloat->x;
    tmp_z = cordfloat->z;
    cordfloat->x = sin(angle) * tmp_x + cos(angle) * tmp_z;
    cordfloat->z = cos(angle) * tmp_z - sin(angle) * tmp_x;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_data	cord;
    t_data_fl cordfloat;
   // t_fdf_opdata opo;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "MinilibX");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.color = 255;
    // while(mlx_hook(mlx_win, KEY_PRESS, KEY_PRESS_MASK, win_hooks, opo))
    //     opo.angle += 10;
    int len = 20;
    int hight = 13;
        int data[13][19] = {
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0, -100, -100,  0,  0, -100, -100,  0,  0,  0, -100, -100, -100, -100, -100,  0,  0,  0},
        {0,  0, -100, -100,  0,  0, -100, -100,  0,  0,  0, -100, -100, -100, -100, -100,  0,  0,  0},
        {0,  0, -100, -100,  0,  0, -100, -100,  0,  0,  0,  0,  0,  0, -100, -100,  0,  0,  0},
        {0,  0, -100, -100, -100, -100, -100, -100,  0,  0,  0,  0, -100, -100, -100, -100,  0,  0,  0},
        {0,  0,  0, -100, -100, -100, -100, -100,  0,  0,  0, -100, -100,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0, -100, -100,  0,  0,  0, -100, -100,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0, -100, -100,  0,  0,  0, -100, -100, -100, -100, -100,  0,  0,  0},
        {0,  0,  0,  0,  0,  0, -100, -100,  0,  0,  0, -100, -100, -100, -100, -100,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};
    int x1,x2,y1,y2;
	y1 = 0;
    y2 = 0;
    while(y2 < hight)
    {
        x1 = 0;
        x2 = 1;
        while(x2 < len)
        {
            cordfloat.x = x1 * X_GAP;
	        cordfloat.y = y1 * Y_GAP;
            cordfloat.z = data[y1][x1];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x1 = cordfloat.x + 300;   
	        cord.y1 = cordfloat.y + 200 + cordfloat.z;
            // isometric(value);
            //z_rotate(cord.x1, cord.y1, 10, 10);
            cordfloat.x = x2 * X_GAP;
	        cordfloat.y = y2 * Y_GAP;
            cordfloat.z = data[y2][x2];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x2 = cordfloat.x + 300;   
	        cord.y2 = cordfloat.y + 200 + cordfloat.z;
            // isometric(cord.x2, cord.y2, z2);
            //z_rotate(cord.x1, cord.y1, 10, 10);
            draw_line(&img, cord);
            mlx_put_image_to_window(mlx, mlx_win, img.img, 400, 200);
            x1++;
            x2++;
        }
        y1++;
        y2++;
    }

    ////////////////////////////////////////////////////////////////////////////////

    x1 = 0;
    x2 = 0;
    while(x2 < len)
    {
        y1 = 0;
        y2 = 1;
        while(y2 < hight)
        {
	        cordfloat.x = x1 * X_GAP;
	        cordfloat.y = y1 * Y_GAP;
            cordfloat.z = data[y1][x1];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x1 = cordfloat.x + 300;   
	        cord.y1 = cordfloat.y + 200 + cordfloat.z;
            printf("x1=%f\n", cordfloat.x);
            printf("y1=%f\n", cordfloat.y);
            //isometric(cord.x1, cord.y1, z1);
            //z_rotate(cord.x1, cord.y1, 10, 10);
            cordfloat.x = x2 * X_GAP;
	        cordfloat.y = y2 * Y_GAP;
            cordfloat.z = data[y2][x2];
            z_rotate(&cordfloat, 45);
            x_rotate(&cordfloat, 30);
            cord.x2 = cordfloat.x + 300;   
	        cord.y2 = cordfloat.y + 200 + cordfloat.z;
            printf("x2=%f\n", cordfloat.x);
            printf("y2=%f\n", cordfloat.y);
            // isometric(cord.x2, cord.y2, z2);
            // z_rotate(cord.x2, cord.y2, 10, 10);
            draw_line(&img, cord);
            mlx_put_image_to_window(mlx, mlx_win, img.img, 400, 200);
            y1++;
            y2++;
        }
        x1++;
        x2++;
    }


    // cord.x1 = 10;
	// cord.y1 = 10;
    // cord.x2 = 10;
    // cord.y2 = 30;
    // draw_line(&img, cord);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 400, 200);
	mlx_loop(mlx);
}

