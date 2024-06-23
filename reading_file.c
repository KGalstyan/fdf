#include "fdf.h"


// int *get_z_value(char *str, int len)
// {
//     char **str_spl;
//     int 
//     int i = 0;
//     int j = 0;

//     str_spl = ft_split(str);
//     while(str_spl[i])
//     {
//     } 
// }

int get_len(char *str)
{
    int len;
    char **split_str;

    split_str = ft_split(str, ' ');
    len = 0;
    while(split_str[len])
        len++;
    free_matrix(split_str);
    return(len);
}


void reading_file(char *av, t_data *param)
{
    int fd;
    char *str;
    char *tmp;

    param->hight = 0;
    tmp = NULL;
    fd = open(av, O_RDONLY);
    str = get_next_line(fd);
    param->len = get_len(str);
    printf("len = %d\n", param->len);
    // z_value = (int **)malloc(sizeof(int *) * (hight + 1));
    while(str)
    {
        printf("%s", str);
        str = get_next_line(fd);
        param->hight++;
    }
    printf("hight is == %d", param->hight);
}