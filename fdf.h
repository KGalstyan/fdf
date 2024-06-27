/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:47:15 by kgalstya          #+#    #+#             */
/*   Updated: 2024/06/27 17:39:40 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define OFF_ESC 53
# define OFF_X 17
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define KEY_PRESS 2
# define KEY_PRESS_MASK 1
# define KEY_PRESS_Z 6
# define KEY_PRESS_X 7
# define KEY_PRESS_Y 16

# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0

# define X_GAP 15
# define Y_GAP 15
# define Z_GAP 15

# include "./Get_next_line/get_next_line.h"
# include "./Printf/ft_printf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
}				t_img;

typedef struct s_data
{
	int			len;
	int			hight;
	int			**z_values;
	int			gap;
	int			center_x;
	int			center_y;

}				t_data;

typedef struct s_data_fl
{
	float		x;
	float		y;
	float		z;

}				t_data_fl;

typedef struct s_point2
{
	int			x2;
	int			x1;
	int			y1;
	int			y2;
}				t_point2;

typedef struct s_point
{
	int			x2;
	int			x1;
	int			y1;
	int			y2;
	t_point2	tmp;
}				t_point;

typedef struct s_line
{
	int			tx;
	int			ty;
	int			dx;
	int			dy;
	int			p;
	int			x;
	int			y;
}				t_line;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	// int     step_right;
	// int     step_down;
	// int angle_x;
	// int angle_y;
	// int angle_z;
}				t_mlx;

// libft
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen(const char *s);
char			*ft_substr(char const *s, int start, int len);
char			*ft_strdup(const char *s);
long long		ft_atoi(const char *nptr);
char			**ft_split(char const *s, char c);

// utils
void			free_matrix(char **str);
void			free_matrix_int(int **str, int len);
// correct file name
int				correct_file(char *av);
int				is_digit(char h);

// reading file
void			reading_file(char *av, t_data *param);
int				**get_z_value(char *str, t_data *param);

// for drawing
void			draw_line(t_img *img, t_point *cord);
void			draw_map(char *av);

// mlx graphic

int				win_hooks(int keycode, t_mlx *mlxparams);
int				close_window(t_mlx *mlxparams);

#endif