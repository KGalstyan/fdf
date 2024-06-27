#include "fdf.h"

void    mlx_pixel_put_img(t_img *img, int x, int y, int color)
{
    char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


static void draw_line_for_x(t_line *line, t_img *img)
{
    int i;
    
    i = -1;
    while(++i < line->dx)
    {
        if(line->tx < 0)
            line->x--;
        else
            line->x++;
        if(line->p < 0)
            line->p = line->p + (2 * line->dy);
        else
        {
            if(line->ty < 0)
                line->y--;
            else
                line->y++;
            line->p = line->p + (2 * line->dy) - (2 * line->dx);
        }
        mlx_pixel_put_img(img, line->x, line->y, img->color);
    }
}

static void draw_line_for_y(t_line *line, t_img *img)
{
    int i;

    i = -1;
    mlx_pixel_put_img(img, line->x, line->y, img->color);
    while(++i < line->dy)
    {
        if(line->ty < 0)
            line->y--;
        else
            line->y++;
        if(line->p < 0)
            line->p = line->p + (2 * line->dx);
        else
        {
            if(line->tx < 0)
                line->x--;
            else
                line->x++;
            line->p = line->p + (2 * line->dx) - (2 * line->dy);
        }
        mlx_pixel_put_img(img, line->x, line->y, img->color);
    }
}   


void draw_line(t_img *img, t_point *cord) 
{
    t_line line;

    line.tx = cord->x2 - cord->x1;
    line.ty = cord->y2 - cord->y1;
    line.dx = abs(cord->x2 - cord->x1);
    line.dy = abs(cord->y2 - cord->y1);
    line.p = 2 * line.dy - line.dx;
    line.x = cord->x1, line.y = cord->y1;

    /////less
	if(line.dx > line.dy)
    {
        line.p = 2 * line.dy - line.dx;
        draw_line_for_x(&line, img);
    }
    ////big
    else
    {
        line.p = 2 * line.dx - line.dy;
        draw_line_for_y(&line, img);
    }
}