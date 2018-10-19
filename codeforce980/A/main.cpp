#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[1000];
int main()
{
    scanf("%s",s);
    int x1=0,x2=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            x1++;
        }else{
            x2++;
        }
    }
    if(x2==0||x1==0||x1%x2==0)
    {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
