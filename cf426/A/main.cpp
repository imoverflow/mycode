#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(char t)
{
    if(t=='^')
        return 0;
    else if(t=='>')
        return 1;
    else if(t=='v')
        return 2;
    else
        return 3;
}
int main()
{
    char a,b;
    scanf("%c %c",&a,&b);
    int t;
    scanf("%d",&t);
    int n=solve(a),m=solve(b);
    int flag1=0,flag2=0;
    if((n+t)%4==m)
        flag1=1;
    if((m+t)%4==n)
        flag2=1;
    if(flag1&&flag2==0)
        printf("cw\n");
    else if(flag2&&flag1==0)
        printf("ccw\n");
    else
        printf("undefined\n");
    return 0;
}
