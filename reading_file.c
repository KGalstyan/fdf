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
    char *tmp2;

    str = "";
    param->hight = 0;
    // z_value = (int **)malloc(sizeof(int *) * (hight + 1));
    fd = open(av, O_RDONLY);
    while(1)
    {
        tmp = get_next_line(fd);
        if(!tmp)
            break;
        param->len = get_len(tmp);
        tmp2 = str;
        str = ft_strjoin(tmp2, tmp);
        //printf("%s", str);
        param->hight++;
        free(tmp);
    }
    printf("len = %d\n", param->len);
    printf("str == %s", str);
    printf("hight is == %d", param->hight);
    free(str);
}