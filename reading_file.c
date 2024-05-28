#include "fdf.h"

// void point_color(char *line)
// {
//     printf("%s", line);
// }

int reading_file(char *av)
{
    int fd;
    char *str;
    

    fd = open(av, O_RDONLY);
    str = get_next_line(fd);
    while()
}