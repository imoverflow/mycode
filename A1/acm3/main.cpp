#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int a,b,c,d,i,j,k;
    float g;
    char e[3],temp,m,n,o;
    while(scanf("%d",&a)!=EOF)
    {
        void score(int a);
        score(a);
    }
    return 0;
}

void score(int a)
{
    if(!(a>=0&a<=100))
        {
            printf("Score is error!\n");
        }else
        {
            int b=a/10;
    switch(b)
    {
    case 10:
        printf("A\n");
        break;
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 6:
        printf("D\n");
        break;
    case 5:
        printf("E\n");
        break;
    case 4:
        printf("E\n");
        break;
    case 3:
        printf("E\n");
        break;
    case 2:
        printf("E\n");
        break;
    case 1:
        printf("E\n");
        break;
    case 0:
        printf("E\n");
        break;
    }
        }

}
