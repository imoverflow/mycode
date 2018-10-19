#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>       //be care of the pow
using namespace std;
int cmp(s)
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        int b;
        char s1[100000][13];
        scanf("%d",&b);
        for(int j=0;j<b;j++)
        {
            scanf("%c %c %c %c %c %c",&s1[b][0],&s1[b][1],&s1[b][2],&s1[b][3],&s1[b][4],&[b]s1[5]);
            strcat(s1[b],s1[b]);
        }
        if(cmp==0)
            printf("No two snowflakes are alike.\n");
        else
            printf("Twin snowflakes found.");
    }
    return 0;
}
