#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct st{
    char s[4];
}m[105];
bool cmp(struct st *a,struct st *b)
{
    return strcmp(a->s,b->s)<0;
}
int main()
{
    int n;
    char home[4],te1[4],te2[4];
    scanf("%d",&n);
    scanf("%s",home);
    getchar();
    int flag=1,k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<8;j++)
        {
            char t;
            t=getchar();
            if(j<3)
            {
                te1[j]=t;
            }else if(j==3||j==4){
                continue;
            }else{
                te1[4]=0;
                te2[j-5]=t;
            }
        }
        te2[4]=0;
        getchar();
        if(strcmp(home,te1)==0)
            strcpy(m[k++].s,te2);
        else if(strcmp(home,te2)==0)
            strcpy(m[k++].s,te1);
        else
            flag=0;
    }
    if(flag)
    {
        sort(m,m+k,cmp);
        for(int i=0;i<k;i+=2)
        {
            if(strcmp(m[i].s,m[i+1].s)!=0)
                flag=0;
        }
    }
    if(flag)
        printf("home");
    else
        printf("contest");
    return 0;
}
