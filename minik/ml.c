#include "minik.h"

void    mlx_pixel_put_img(t_img *img, int x, int y, int color)
{
    char	*dst;

	dst = img->addr + (x * img->line_length + y * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void draw_line(t_img *img, t_data cord) 
{
    int dx = abs(cord.x2 - cord.x1);
    int dy = abs(cord.y2 - cord.y1);
    int p = 2 * dy - dx;
    int x = cord.x1, y = cord.y1;
	int i = 0;

	if(dx > dy)
    {
        // i = 0;
        // while(i < dy)
        // {
        //     y++;
        //     mlx_pixel_put_img(img, x, y, img->color);
        //     if(p < 0)
        //       p = p + (2 * dy);
        //     else
        //     {
        //         p = p + (2 * dy) - (2 * dx);
        //         x++;
        //     }
        //     mlx_pixel_put_img(img, x, y, img->color);
        //     i++;
        // }
        i = -1;
        while(++i < dx)
        {
            if(p < 0)
              p = p + (2 * dy);
            else
            {
                p = p + (2 * dy) - (2 * dx);
                y++;
            }
            mlx_pixel_put_img(img, x, y, img->color);
            i++;
        }
    }
    else
    {
        // i = -1;
        // while(++i < dx)
        // {
        //     if(p < 0)
        //         p = p + (2 * dy);
        //     else
        //     {
        //         p = p + (2 * dy) - (2 * dx);
        //         y++;
        //     }
        //     mlx_pixel_put_img(img, x, y, img->color);
        //     i++;
        // }
        i = 0;
        mlx_pixel_put_img(img, x, y, img->color);
        while(i < dy)
        {
            x++;
            if(p < 0)
              p = p + (2 * dy);
            else
            {
                p = p + (2 * dy) - (2 * dx);
                y++;
            }
            mlx_pixel_put_img(img, x, y, img->color);
            i++;
        }
    }
}
    // int sx = cord.x1 < cord.x2 ? 1 : -1;
    // int sy = cord.y1 < cord.y2 ? 1 : -1;

    // while (x != cord.x2 || y != cord.y2)
    // {
    //     if (p >= 0) {
    //         if (p >= dy) 
    //         {
    //             x += sx;
    //             p -= dy;
    //         }
    //         if (p <= dx) 
    //         {
    //             y += sy;
    //             p += dx;
    //         }
    //     } 
    //     else 
    //     {
    //         if (p <= -dx) 
    //         {
    //             y += sy;
    //             p += dx;
    //         }
    //         if (p >= -dy) 
    //         {
    //             x += sx;
    //             p -= dy;
    //         }
    //     }
    //     mlx_pixel_put_img(img, x, y, img->color);
    // }
//}



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
	cord.x1 = 20;
	cord.y1 = 20;
    cord.x2 = 700;
    cord.y2 = 200;
	draw_line(&img, cord);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

