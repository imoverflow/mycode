#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[100000];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=0;i<m;i++){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        int cnt1=0;
        if(x<=r&&x>=l)
        {
            for(int i=l-1;i<r;i++)
            {
                if(s[x-1]>s[i])
                    cnt1++;
            }
            if(cnt1+l==x)
                puts("Yes");
            else
                puts("No");
        }else{
            puts("Yes");
        }
    }
    return 0;
}
