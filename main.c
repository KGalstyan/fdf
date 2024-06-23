#include "fdf.h"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        if(!correct_file(argv[1]))
            exit(1);
        else
        {
            draw_map(argv[1]);
            printf("ALL RIGHT BRO");
        }
    }
    else
        printf("please enter file name\n");
    // system("leaks fdf");
    return(0);
}
