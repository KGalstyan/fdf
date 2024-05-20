#include "fdf.h"

int	is_digit(char h)
{
	return (h >= '0' && h <= '9');
}

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

    split_str = ft_splir(str, ' ');
    i = 0;
    while(split_str[i])
    {
        j = 0;
        while(split_str[i][j])
        {
            if(!is_digit(split_str[i][j]))
                return(1);
            j++;
        }
        i++;
    }
    free_matrix(split_str);
    return(0);
}

int correct_file(char *av)
{
    int fd;
    char *str;

    if(!correct_file_name(av))
        return(1);
    fd = open(av, O_RDONLY);
    if(fd == -1)
        return(1);
    str = get_next_line(fd);
    while(str)
    {
        correct_arguments(str);
        //printf("%s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    return(0);
}
