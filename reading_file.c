#include "fdf.h"

// void point_color(char *line)
// {
//     printf("%s", line);
// }



int read_incert_file(char *str)
{
    int i;
    char **z_value;

    z_value = ft_split(str, ' ');
    i = 0;
    while(z_value[i])
    {
        if((ft_atoi(z_value[i]) > 100000) && (ft_atoi(z_value[i]) < -100000))
        {
            free_matrix(z_value);
            return(0);
        }
        i++;
    }
    return(1);
}

int reading_file(char *av)
{
    int fd;
    char *str;

    fd = open(av, O_RDONLY);
    if(fd == -1)
        return(1);
    str = get_next_line(fd);
    while(str)
    {
        if(!read_incert_file(str, point))
        {
            free(str)
            return(1);
        }
        free(str);
        str = get_next_line(fd);
    }
    return(0);
}