#include "fdf.h"


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

int *read_file(char *av)
{
    int fd;
    char *str;
    char **split_str;
    int len;
    int hight;
    int *z_value;

    fd = open(av, O_RDONLY);
    str = get_next_line(fd);
    len = get_len(str);
    printf(len);
    while(str)
    {
        get_z_value()
    }
}