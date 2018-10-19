#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[100000];
char s1[10];
char s2[10];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%s",s1);
        scanf("%s",s2);
        for(int j=a-1;j<=b-1;j++)
        {
            if(s[j]==s1[0])
                s[j]=s2[0];
        }
    }
    printf("%s\n",s);
    return 0;
}
