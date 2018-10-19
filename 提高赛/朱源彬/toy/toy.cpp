#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

struct node{
    int face;
    int id;
    char name[15];
}s[100005];
int main()
{
    freopen("toy.in","r",stdin);
    freopen("toy.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        s[i].id=i;
        scanf("%d",&s[i].face);
        scanf("%s",s[i].name);
    }
    int flag=0;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(s[flag].face==0)
        {
            if(a==0)
            {
                flag-=b;
            }else{
                flag+=b;
            }
        }else if(s[flag].face==1)
        {
            if(a==0)
            {
                flag+=b;
            }else{
                flag-=b;
            }
        }
        while(flag<0)
            flag+=n;
        while(flag>n)
            flag-=n;
    }
    printf("%s",s[flag].name);
    return 0;
}
