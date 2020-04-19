#include <stdio.h>
#include <stdlib.h>
#include "runner.h"
int main(int argc, char const *argv[])
{
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    int status = runner(fptr);
    return status;
}
