#include "fdf.h"

int main(int argc, char **argv)
{
    t_all a;

    if(argc == 2)
    {
        if(!correct_file(argv[1]))
            return(0);
        else
        {
            printf("ALL RIGHT BRO");
            get_mlx_data(&a);
        } 
        // reading_file(*argv);
    }
    else
        printf("please enter file name\n");
    // system("leaks fdf");
    return(0);
}
