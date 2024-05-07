#include "fdf.h"

int	is_digit(char h)
{
	return (h >= '0' && h <= '9');
}


int correct_file_name(char *av)
{
    int len = 0;

    len = ft_strlen(av) - 4;
    if(av[0] != '.' && (ft_strcmp(".fdf", av+len) == 0))
        return(1);
    return(0);
}

void point_color(char *line)
{
    printf("%s", line);
}

// int read_incert_file(char *str)
// {
// }


int correct_read_file(char *av)
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
        //read_incert_file(str);
        printf("%s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    return(0);
}
