// #include "fdf.h"

// void    mlx_pixel_put_img(t_img *img, int x, int y, int color)
// {
//     char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// // int	is_steep(int dy, int dx);
// // {
// //     return (dy > dx);
// // }

// // void  isometric(t_point cord)
// // {
// //     int tmp;

// //     tmp = cord;
// //     x = (tmp - y) * cos(0.523599);
// //     y = (tmp + y) * sin(0.523599) - z;
// // }

// void draw_line(t_img *img, t_data cord) 
// {
//     t_line line;
//     line.tx= cord.x2 - cord.x1;
//     line.ty = cord.y2 - cord.y1;
//     line.dx = abs(cord.x2 - cord.x1);
//     line.dy = abs(cord.y2 - cord.y1);
//     line.p = 2 * line.dy - line.dx;
//     line.x = cord.x1;
//     line.y = cord.y1;

//     // t_point point;
// 	if(dx > dy)
//         draw_for_dx()

//     else
//     {
//         p = 2 * tx - ty;
//         i = 0;
//         mlx_pixel_put_img(img, x, y, img->color);
//         while(i < dy)
//         {
//             if(ty > 0)
//                 y++;
//             else
//                 y--;
//             if(p < 0 && tx >= 0)
//               p = p + (2 * tx);
//             else
//             {
//                 if(tx > 0)
//                     x++;
//                 else
//                     x--;
//                 p = p + (2 * tx) - (2 * ty);
//             }
//             mlx_pixel_put_img(img, x, y, img->color);
//             i++;
//         }
//     }
// }

// static void draw_for_dx()
// {
//     int i;

//     i = -1;
//     while(++i < dx)
//     {
//         if(tx > 0)
//             x++;
//         else
//             x--;
//         if(p < 0)
//           p = p + (2 * dy);
//         else
//         {
//             p = p + (2 * dy) - (2 * dx);
//         if(ty > 0)
//                 y++;
//             else
//                 y--;
//         }
//         mlx_pixel_put_img(img, x, y, img->color);
//     }
// }