#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
    //freopen("a.txt","r",stdin);
    int n,a,total,summit;
    char s[105][40];
    char date[105][10];
    char statu[105][15];
    int num[105];
    char ac[50];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<15;k++)
        {
            statu[i][k]='.';
        }
        gets(s[i]);
        scanf("%s",date[i]);
        scanf("%d %d",&total,&summit);
        getchar();
        num[i]=total;
        for(int j=0;j<summit;j++)
        {
            char t;
            scanf("%c",&t);
            getchar();
            gets(ac);
            if(strcmp(ac,"Accepted")==0)
            {
                statu[i][t-'A']='o';
            }else if(statu[i][t-'A']!='o'&&strcmp(ac,"Accepted")!=0)
            {
                statu[i][t-'A']='x';
            }
        }
    }
    printf("+------------------------------+--------+-------------+\n|Contest name                  |Date    |ABCDEFGHIJKLM|\n+------------------------------+--------+-------------+\n");
    for(int i=0;i<n;i++)
    {
        printf("|%-30s|",s[i]);
        printf("%s|",date[i]);
        for(int j=0;j<13;j++)
        {
            if(j<num[i])
                printf("%c",statu[i][j]);
            else
                printf(" ");
        }
        printf("|\n");
        printf("+------------------------------+--------+-------------+\n");
    }
    return 0;
}
