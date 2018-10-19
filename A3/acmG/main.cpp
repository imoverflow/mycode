#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>       //be care of the pow
using namespace std;
int s2[2000]={0};
int N;
int cou=0;
char st[100000];
int po(int a,int b)
{
    int sum=1;
    for(int i=0;i<b;i++)
    {
        sum*=a;
    }
    return sum;
}
void digui1(int sta,int en)
{
    int sum=0;
    for(int i=sta;i<en;i++)
    {
        sum+=s2[i];
    }
    if(en-sta!=0)
    {
        if(sum==en-sta)
        {
            st[cou++]='I';
            if(sta!=0)
            digui1(en/2,en);
        }
        else if(sum==0)
        {
            st[cou++]='B';
            if(sta!=0)
            digui1(en/2,en);
        }
        else if(sum>0&&sum<en-sta)
        {
            st[cou++]='F';
            if(sta!=0)
            digui1(en/2,en);
        }
        digui1(sta,en/2);
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {

        char s1[2000];
        s2[2000]={0};
        scanf("%d",&N);
        getchar();
        gets(s1);
        for(int j=0;j<po(2,N);j++)
        {
            s2[j]=s1[j]-'0';
        }
        digui1(0,po(2,N));
        for(int j=cou-1;j>=0;j--)
        {
            printf("%c",st[j]);
        }
        printf("\n");
    }
    return 0;
}
