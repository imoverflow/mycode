#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    //freopen("abc.txt","r",stdin);
    int a,b,c,d;
    int s[100][2];
    float sum;
    while(scanf("%d",&a)!=EOF)
    {
        if(a==0)
        exit(0);
        s[100][2]={0};
        sum=0;
        for(int i=0;i<a*2;i++)
        {
            scanf("%d",&b);
            s[i/2][i%2]=b;
        }
        for(int i=2;i<a*2;i++)
        {
            if(i%2==0)
            s[i/2][i%2]-=s[0][0];
            else
            s[i/2][i%2]-=s[0][1];
        }
        s[a][0]=s[0][0];
        s[a][1]=s[0][1];
        int chaji(int x1,int y1,int x2,int y2);
        for(int i=1;i<a-1;i++)
        {
            sum+=chaji(s[i][0],s[i][1],s[i+1][0],s[i+1][1]);
        }
        if(sum<0)
            sum=-sum;
        printf("%.1f\n",sum/2);

    }
    return 0;
}

int chaji(int x1,int y1,int x2,int y2)
{
    int sum;
    sum=x1*y2-x2*y1;
    return sum;
}
