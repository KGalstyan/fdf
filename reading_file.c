#include "fdf.h"


int **get_z_value(char *str,t_data *param)
{
    char **str_spl_line;
    char **str_spl_args;
    int **z_values;
    int i = 0;
    int j = 0;

    str_spl_line = ft_split(str, '\n');
    z_values = (int **)malloc(sizeof(int *) * (param->hight`)); 
    while(str_spl_line[i])
    {
        j = 0;
        str_spl_args = ft_split(str_spl_line[i], ' ');
        z_values[i] = (int *)malloc(sizeof(int) * (param->len));
        while(str_spl_args[j])
        {
            z_values[i][j] = ft_atoi(str_spl_args[j]);
            j++;
        }
        free_matrix(str_spl_args);
        i++;
    }
    free_matrix(str_spl_line);
    return(z_values);
}

int get_len(char *str)
{
    int len;
    char **split_str;

    split_str = ft_split(str, ' ');
    len = 0;
    while(split_str[len] && split_str[len][0] != '\n')
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
    ////////////////////////
    //int x = 0;
    //int y = 0;
    ////////////////////////

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
    //printf("len = %d\n", param->len);
    //printf("str == %s", str);
    param->z_values = get_z_value(str, param);
    //printf("hight is == %d", param->hight);

//////////////////////////////////////////////////////////////////

    // while(y < param->hight)
    // {
    //     x = 0;
    //     while(x < param->len)
    //     {
    //         printf("%d", param->z_values[y][x]);
    //         x++;
    //     }
    //     printf("\n");
    //     y++;
    // }

//////////////////////////////////////////////////////////////////
    free(str);
    close(fd);
}