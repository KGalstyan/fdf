#ifndef MINIK_H
#define MINIK_H
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     color;
}				t_img;

typedef struct  s_data
{
    int x1;
    int x2;
    int y1;
    int y2;
    int x3;
    int y3;
}               t_data;

// typedef struct  s_line
// {
//     int dx;
//     int dy;
//     int p;
//     int x;
//     int y;
//     int i;
// }               t_line;

#endif