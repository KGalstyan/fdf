#include "fdf.h"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        if(correct_file(argv[1]))
        {
            printf("chee axprs dyuzn inch sxal e\n");
            return(0);
        }
        if(reading_file(argv[1]))
        {
            printf("es mejy inch a?");
            return(0);
        }    
    }
    else
        printf("please enter file name\n");
    system("leaks fdf");
    return(0);
}
