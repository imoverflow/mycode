#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

char s[105][105][105];
char t[205][205];
int n;
int check(int a[])
{
    int ans=0;
    for(int j=0;j<n;j++)
    {
        for(int z=0;z<n;z++)
        {
            t[j][z]=s[a[0]][j][z];
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int z=n;z<2*n;z++)
        {
            t[j][z]=s[a[1]][j][z-n];
        }
    }
    for(int j=n;j<2*n;j++)
    {
        for(int z=0;z<n;z++)
        {
            t[j][z]=s[a[2]][j-n][z];
        }
    }
    for(int j=n;j<2*n;j++)
    {
        for(int z=n;z<2*n;z++)
        {
            t[j][z]=s[a[3]][j-n][z-n];
        }
    }
    int ans1=0;
    char now='1';
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            if(t[i][j]!=now)
                ans1++;
            if(now=='1')
                now='0';
            else
                now='1';
        }
        if(now=='1')
            now='0';
        else
            now='1';
    }
    int ans2=0;
    now='0';
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            if(t[i][j]!=now)
                ans2++;
            if(now=='1')
                now='0';
            else
                now='1';
        }
        if(now=='1')
                now='0';
            else
                now='1';
    }
    ans=min(ans1,ans2);
//    for(int i=0;i<2*n;i++)
//    {
//        for(int j=0;j<2*n;j++)
//        {
//            cout<<t[i][j];
//        }
//        cout<<endl;
//    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%s",s[i][j]);
        }
    }
    int ans=INF;
    int a[]={0,1,2,3};
    do
    {
        ans=min(ans,check(a));
    }while(next_permutation(a,a+4));
    cout<<ans<<endl;
    return 0;
}
