#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fi[100];
int sg[1005];
int s[1005];
void creatfi()
{
    fi[1]=1;
    fi[2]=2;
    for(int i=3;i<20;i++)
    {
        fi[i]=fi[i-1]+fi[i-2];
    }
}
void getsg()
{
    memset(sg,0,sizeof sg);
    for(int i=1;i<1001;i++)
    {
        memset(s,0,sizeof s);
        for(int j=1;fi[j]<=i;j++)
        {
            s[sg[i-fi[j]]]=1;
        }
        for(int j=0;j<1001;j++)
        {
            if(s[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}
int main()
{
    creatfi();
    getsg();
    int n,m,p;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        if(n==0&&m==0&&p==0) break;
        if((sg[n]^sg[m]^sg[p]))
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}
