#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s[3];
    for(int i=0;i<3;i++)
    {
        scanf("%d",&s[i]);
    }
    sort(s,s+3);
    if(s[0]>3) printf("NO\n");
    else if(s[0]==3)
    {
        if(s[2]==3) printf("YES\n");
        else printf("NO\n");
    }else if(s[1]==2||(s[1]==4&&s[2]==4)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
