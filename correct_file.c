#include "fdf.h"

static int correct_file_name(char *av)
{
    int len = 0;

    len = ft_strlen(av) - 4;
    if(av[0] != '.' && (ft_strcmp(".fdf", av+len) == 0))
        return(1);
    return(0);
}


static int correct_arguments(char *str)
{
    int j;
    int i;
    char **split_str;

    split_str = ft_split(str, ' ');
    i = 0;
    while(split_str[i])
    {
        if((ft_atoi(split_str[i]) > 100000) || (ft_atoi(split_str[i]) < -100000))
        {
            printf("MAX-MIN ERROR");
            free_matrix(split_str);
            return(0);
        }
        j = 0;
        while(split_str[i][j] != '\n' && split_str[i][j] != '\0')
        {
            if (!(is_digit(split_str[i][j])))
            {
                printf("IS NOT DIGIT");
                free_matrix(split_str);
                return(0);
            }
            j++;
        }
        i++;
    }
    free_matrix(split_str);
    return(i);
}


int correct_file(char *av)
{
    int fd;
    char *str;
    int len;
    //int **z_values;

    if(!correct_file_name(av))
    {
        printf("INcorrect filename");
        return(0);
    }
    fd = open(av, O_RDONLY);
    if(fd == -1)
    {
        printf("INcorrect filename or can't open file");
        return(0);
    }
    str = get_next_line(fd);
    if(!str)
    {
        printf("Nothing in file");
        return(0);
    }
    len = correct_arguments(str);
    while(str)
    {
        if(correct_arguments(str) == 0 || correct_arguments(str) != len)
        {
            if(correct_arguments(str) != len)
                printf("len is incorrect");
            free(str);
            return(0);
        }
        free(str);
        str = get_next_line(fd);
    }
    return(1);
}
