#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n,k;
    char st[10],name[100];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int flag=0,flag1=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s%s",st,name);
            if(st[0]=='i')
            {
                sum+=strlen(name);
            }
            if(st[0]=='o')
            {
                sum-=strlen(name);
            }
            if(strcmp("wnm",name)==0)
            {
                flag=1;
            }
            if(flag)
            {
                if(sum%k==0&&flag1==0)
                    flag1=i;
            }
        }
        if(flag1)
            printf("^_^ %d\n",flag1);
        else
            printf("T_T\n");
    }
    return 0;
}
