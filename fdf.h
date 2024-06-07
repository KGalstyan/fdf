#ifndef FDF_H
#define FDF_H

#define OFF_ESC 53
#define OFF_X 20
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

# define KEY_PRESS 2
# define KEY_PRESS_MASK 1

# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "./Get_next_line/get_next_line.h"
#include <mlx.h>


typedef struct s_point
{
    int x;
    int y;
    int z;
    // int color;
}               t_point;


typedef struct s_all
{
    void *mlx;
    void *mlx_win;

}              t_all;

typedef struct s_img
{
    void *img;
    char *addr;
    int bpp;
    int size_line;
    int endian;
    int color;

}              t_img;

typedef struct s_map
{
    t_point p1;
    t_point p2;
    int **z_value;

}               t_map;





//libft
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strlen(const char *s);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s);
long long	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);


//utils
void	free_matrix(char **str);


//correct file name
int correct_file(char *av);
int	is_digit(char h);

//reading file
// void reading_file(char *av);
// int read_incert_file(char *str);


//for drawing
void  isometric(int x, int y, int z);

//mlx graphic
void get_mlx_data(t_all *a);

#endif