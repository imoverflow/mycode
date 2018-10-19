#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    for(int i=0;i<100;i++)
    {
        printf("%ld\n",((double)rand()/RAND_MAX*50000));
    }
    return 0;
}
