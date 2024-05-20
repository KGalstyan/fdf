#ifndef MINIK_H
#define MINIK_H
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

void draw_line(void *mlx, void *mlx_win);
void	free_stack(t_stack **stack);
void	free_matrix(char **str);


#endif