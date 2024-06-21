#include "fdf.h"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        if(!correct_file(argv[1]))
            return(0);
        else
        {
            printf("ALL RIGHT BRO");
            draw_map(argv[1]);
        }
    }
    else
        printf("please enter file name\n");
    // system("leaks fdf");
    return(0);
}
