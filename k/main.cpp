#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    long n;
    int sum=0,count=0,i,s[10],t;
    scanf("%ld",&n);
    while(n!=0)
    {
        sum+=n%10;
        s[count]=n%10;
        n/=10;
        count++;
    }
    if(count==6)
    {
        printf("%d\n",sum);
         for(i=0;i<count-1;i++)
        {
            for(int j=i+1;j<count;j++)
            {
                if(s[i]<s[j])
                {
                    t=s[j];
                    s[j]=s[i];
                    s[i]=t;
                }
            }
        }
        for(i=0;i<6;i++)
        {
            printf("%d",s[i]);
        }
    } else
        printf("Error\n");

    return 0;
}
