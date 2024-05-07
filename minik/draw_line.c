#include "minik.h"

void draw_line(t_data *img, void *mlx_win)
{
    int x0 = 1;
    int y0 = 2;
    int x1 = 5;
    int y1 = 6;
    int dx;
    int dy;
    int p;
    int x = x0;
    int y = y0;

    dx = abc(x1 - x0);
    dy = abc(y1 - y0);
    p = 2 * dy - dx;

    while(x < x1)
    {
        printf("1");
        mlx_pixel_put(&img, mlx_win, x, y, 0x000000FF);
        x++;
        if(p < 0)
            p = p + (2 * dy);
        else
        {
            p = p + (2 * dy) - (2 * dx);
            y++;
        }
    }
}
