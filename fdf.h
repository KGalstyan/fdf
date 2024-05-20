#ifndef FDF_H
#define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "./Get_next_line/get_next_line.h"
#include <mlx.h>


// typedef struct s_point
// {
//     int x;
//     int y;
//     int z;
//     int x_previous;
//     int y_previous;
//     int y_previous;
//     int color;
//     int color_previous;
// }              t_point;

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

//reading file
int reading_file(char *av);
void read_incert_file(char *str);


//for drawing
void  isometric(int x, int y, int z);


#endif