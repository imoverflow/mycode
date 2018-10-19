#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[200005];
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    scanf("%s",s);
    int len=strlen(s);
    long long ans=0;
    if(a<b)
        swap(a,b);
    int flag=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='.')
        {
            if(flag==0)
            {
                if(a>b)
                {
                    if(a>0)
                    {
                        a--;
                        ans++;
                        flag=2;
                    }else if(b>0){
                        b--;
                        ans++;
                        flag=1;
                    }else{
                        break;
                    }
                }else{
                    if(b>0)
                    {
                        b--;
                        ans++;
                        flag=1;
                    }else if(a>0){
                        a--;
                        ans++;
                        flag=2;
                    }else{
                        break;
                    }
                }
            }else if(flag==1){
                if(a>0)
                {
                    a--;
                    ans++;
                    flag=2;
                }else{
                    flag=0;
                }
            }else if(flag==2)
            {
                if(b>0)
                {
                    b--;
                    ans++;
                    flag=1;
                }else{
                    flag=1;
                }
            }
        }else{
            flag=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
