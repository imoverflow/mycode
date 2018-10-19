#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[100005];
int t[100005];
int p1[100005];
int p2[100005];
int p3[100005];
int p4[100005];
int main()
{
    int n;
    long long res1=0,res2=0;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char a;
        a=getchar();
        s[i]=a-'0';
    }
    getchar();
    for(int i=0;i<n;i++)
    {
        char a;
        a=getchar();
        t[i]=a-'0';
    }
    long long res3=0,res4=0;
    for(int i=n-1;i>=0;i--)
    {
        p1[i]=p1[i+1]+(s[i]+t[i]==2);
        p2[i]=p2[i+1]+(s[i]+t[i]==0);
        p3[i]=p3[i+1]+(s[i]==1&&t[i]==0);
        p4[i]=p4[i+1]+(s[i]==0&&t[i]==1);
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==0&&t[i]==1)
        {
            ans+=p3[i+1];
        }else if(s[i]==0&&t[i]==0)
        {
            ans+=p1[i+1]+p3[i+1];
        }else if(s[i]==1&&t[i]==0){
            ans+=p2[i+1]+p4[i+1];
        }else if(s[i]==1&&t[i]==1){
            ans+=p2[i+1];
        }
//        cout<<ans<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}
