#include "fdf.h"


int *get_z_value(char *str, int len)
{
    char **str_spl;
    int 
    int i = 0;
    int j = 0;

    str_spl = ft_split(str);
    while(str_spl[i])
    {
    } 
}

int get_len(char *str)
{
    int len;
    char **split_str;

    split_str = ft_split(str);
    len = 0;
    while(split_str[len])
        len++;
    free_matrix(split_str);
    return(len);
}

int get_hight(int fd)
{
    char *str;
    int hight;

    hight = 0;
    str = get_next_line(fd);
    while(str)
    {
        hight++;
    }
    return(hight);
}

int **read_file(char *av)
{
    int fd;
    char *str;
    int len;
    int hight;
    int **z_value;

    fd = open(av, O_RDONLY);
    str = get_next_line(fd);
    hight = get_hight(fd);
    len = get_len(str);
    printf(len);
    z_value = (int **)malloc(sizeof(int *) * (hight + 1));
    while(str)
    {
        z_value[i] = (int *)malloc(sizeof(int) * (len + 1));
        get_z_value(len);
    }
}