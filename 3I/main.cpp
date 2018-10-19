#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,cou=0,s[10000];
    scanf("%d",&n);
    if(n==0)
        printf("0\n");
    else
    {

        while(n)
        {
            s[cou++]=n%(-2);
            if(s[cou-1]<0)
                s[cou-1]=-s[cou-1];
            n=(n-s[cou-1])/(-2);
        }
        for(int i=cou-1;i>=0;i--)
        {
            printf("%d",s[i]);
        }
    }
    return 0;
}
