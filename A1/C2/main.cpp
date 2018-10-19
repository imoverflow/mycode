#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i=1,j,k,sum;
    while(i<=1000)
    {
        sum=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
                sum+=j;
        }
        if(sum==i)
        {
            printf("%d its factors are ",i);
            for(k=1;k<i;k++)
            {
                if(i%k==0)
                {
                    printf("%d,",k);
                }
            }
            printf("\n");
        }
        i++;
    }
    return 0;
}
