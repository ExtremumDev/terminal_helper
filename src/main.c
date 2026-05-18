#include <stdio.h>
#include "math.h"


int main(int argc, char **argv)
{

    if (argc == 1)
    {
        puts("You forgot to give me some arguments!");
        return 0;
    }

    char *expression = argv[1];

    if (check_correct_expression(expression))
    {
        puts("Your expression is correct");
    } else {
        puts("Expression consist of incorrect characters");
    }
    


    return 0;
}