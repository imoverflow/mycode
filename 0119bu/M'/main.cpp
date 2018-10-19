#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double s[1005];
double ans[1005];
int n,r;
double cal(int x,int y)
{
    return sqrt((2*r)*(2*r)-abs(x-y)*abs(x-y));
}

int main()
{
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
        ans[i]=r;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]+r>=s[j]-r&&s[i]+r<=s[j]||s[i]-r<=s[j]+r&&s[i]+r>=s[j])
            {
                ans[i]=max(ans[i],ans[j]+cal(s[i],s[j]));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%.10f ",ans[i]);
    }
    return 0;
}
