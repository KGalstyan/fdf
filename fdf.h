#ifndef FDF_H
#define FDF_H

#define OFF_ESC 53
#define OFF_X 17
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

# define KEY_PRESS 2
# define KEY_PRESS_MASK 1
# define KEY_PRESS_Z 6
# define KEY_PRESS_X 7
# define KEY_PRESS_Y 16

# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0

#define X_GAP 25
#define Y_GAP 25

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "./Get_next_line/get_next_line.h"
#include "mlx.h"


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
    int len;
    int hight;
    int **z_values;
    int angle_x;
    int angle_y;
    int angle_z;

}               t_data;

typedef struct  s_data_fl
{
    float x;
    float y;
    float z;

}               t_data_fl;

typedef struct  s_point
{
    int x2;
    int x1;
    int y1;
    int y2;

}               t_point;

typedef struct s_line
{
    int tx;
    int ty;
    int dx;
    int dy;
    int p;
    int x;
    int y;
}               t_line;

typedef struct s_mlx
{
    void	*mlx;
	void	*mlx_win;
}              t_mlx;



void    draw_map(char *av);
int **get_z_value(char *str, t_data *param);






// typedef struct s_map
// {
//     t_point p1;
//     t_point p2;
//     int **z_value;

// }               t_map;

// typedef struct s_map
// {
//     int len;
//     int hight;
//     int **z_value;
// }               t_point;







//libft
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strlen(const char *s);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s);
long long	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);

//utils
void	free_matrix(char **str);
void	free_matrix_int(int **str, int len);
//correct file name
int correct_file(char *av);
int	is_digit(char h);

//reading file
// void reading_file(char *av);
// int read_incert_file(char *str);
void reading_file(char *av, t_data *param);


//for drawing
void draw_line(t_img *img, t_point *cord);

//mlx graphic

int win_hooks(int keycode, t_mlx *mlxparams);
int close_window(t_mlx *mlxparams);
//void get_mlx_data(t_all *a);
//int win_hooks(int keycode, t_all *a);


#endif