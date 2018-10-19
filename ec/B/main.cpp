#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[20005];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int l=0,r=1;
    int ansl,ansr;
    while(r!=len)
    {
        if(s[l]>=s[r])
        {
            r++;
            ansl=l;
            ansr=r;
        }else{
            l=r;
        }
    }
    for(int i=ansl;i<=ansr;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}
