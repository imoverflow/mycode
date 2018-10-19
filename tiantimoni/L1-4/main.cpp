#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s[100005];
int main()
{
    int cnt=0;
    for(int i=0;;i++)
    {
        cin>>s[i];
        if(s[i]==".")
            break;
        cnt++;
    }
    if(cnt<2)
        printf("Momo... No one is for you ...\n");
    else if(cnt>=2&&cnt<14)
    {
        cout<<s[1];
        printf(" is the only one for you...\n");
    }else{
        cout<<s[1]<<" and "<<s[13]<<" are inviting you to dinner..."<<endl;
    }
    return 0;
}
