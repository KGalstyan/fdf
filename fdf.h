#ifndef FDF_H
#define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "./Get_next_line/get_next_line.h"
#include <mlx.h>


struct s_point
{
    int x;
    int y;
    int z;
    int color;
    int corner;

}   t_point;


int	ft_strcmp(const char *s1, const char *s2);
int correct_file_name(char *av);
int	ft_strlen(const char *s);
int correct_read_file(char *av);
long long	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
//int read_incert_file(char *str);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s);



#endif