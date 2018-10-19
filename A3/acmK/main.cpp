#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>       //be care of the pow
using namespace std;

int main()
{
    int a;
    scanf("%d",&a);
    getchar();
    char s[55],t;
    for(int i=0;i<a;i++)
    {
        gets(s);
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]>='0'&&s[j]<='9')
            {
                for(int k=0;k<s[j]-'0';k++)
                {
                    printf("%c",t);
                }
            }else
            {
                t=s[j];
                printf("%c",t);
            }
        }
        printf("\n");
    }
    return 0;
}
