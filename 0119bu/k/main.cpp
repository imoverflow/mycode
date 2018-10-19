#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[55];
    cin>>s;
    int cnt=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if((s[i]-'0')%2==1)
            {
                cnt++;
            }
        }else if(s[i]>='a'&&s[i]<='z')
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
