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

// void  isometric(t_point cord)
// {
//     int tmp;

//     tmp = cord;
//     x = (tmp - y) * cos(0.523599);
//     y = (tmp + y) * sin(0.523599) - z;
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
            if(p < 0 && tx > 0)
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_data	cord;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "MinilibX");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.color = 255;
	cord.x1 = 200;
	cord.y1 = 200;
    cord.x2 = 150;
    cord.y2 = 300;
    draw_line(&img, cord);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 400, 200);
    cord.x1 = 200;
	cord.y1 = 200;
    cord.x2 = 100;
    cord.y2 = 280;
    draw_line(&img, cord);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 400, 200);
	mlx_loop(mlx);
}

