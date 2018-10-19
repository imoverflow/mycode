#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[100];
    char c[100];
    for(int i=0;i,n;i++)
    {
        if(c[i]>='A'&&c[i]<='Z')
            printf("%d\n",c[i]-'A'+1+a[i]);
        if(c[i]>='a'&&c[i]<='z')
            printf("%d\n",(c[i]-'a')*(-1)-1+a[i]);
    }
    return 0;
}










