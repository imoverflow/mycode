#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[65][100];
char t[10]="STEED";
int main()
{
    sort(t,t+5);
    for(int i=1;i<=60;i++)
    {
        strcpy(s[i],t);
        next_permutation(t,t+5);
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%s\n",s[n]);
    }
    return 0;
}
