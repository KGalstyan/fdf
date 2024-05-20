#include "minik.h"

// void  isometric(int x, int y, int z)
// {
//  int tmp;

//  tmp = x;
//  x = (tmp - y) * cos(0.523599);
//  y = (tmp + y) * sin(0.523599) - z;
// }


void draw_line(void *mlx, void *mlx_win)
{
    int i;
    int x0 = 1;
    int y0 = 1;
    int x1 = 8;
    int y1 = 5;
    int dx;
    int dy;
    int p;
    int x = x0;
    int y = y0;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    p = (2 * dy) - dx;

    if(dx > dy)
    {
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
            mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFFFF)
            i++;
        }
    }
    else
    {
        i = 0;
        while(i < dy)
        {
            y++;
            mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFFFF);
            if(p < 0)
              p = p + (2 * dy);
            else
            {
                p = p + (2 * dy) - (2 * dx);
                x++;
            }
            mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFFFF);
            i++;
        }
    }
}
