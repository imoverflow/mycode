#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s;
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    getline(cin,s);
    int len=s.length();
    if(n==1)
    {
        for(int i=len-1;i>=0;i--)
        {
            printf("%c",s[i]);
        }
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=(len-1)/n*n+i-((len-1)%n==0);j>=0;j-=n)
        {
            if(j>=len)
                printf(" ");
            else
                printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}
