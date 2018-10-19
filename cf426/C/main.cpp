#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x1[10000006];
int x2[10000006];
int cnt1,cnt2;
vector<int>v;
void div1(int a)
{
    for(int i=2;i<=a;i++)
    {
        if(a%i==0)
        {
            v.push_back(i);
            cnt1++;
            while(a%i==0)
            {
                x1[i]++;
                a/=i;
            }
        }
    }
}
void div2(int b)
{
    for(int i=2;i<=b;i++)
    {
        if(b%i==0)
        {
            cnt2++;
            while(b%i==0)
            {
                x2[i]++;
                b/=i;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        cnt1=cnt2=0;
        v.clear();
        memset(x1,0,sizeof x1);
        memset(x2,0,sizeof x2);
        int a,b;
        scanf("%d%d",&a,&b);
        div1(a);
        div2(b);
        if(cnt1!=cnt2)
        {
            printf("NO\n");
            continue;
        }
        int len=v.size();
        int flag=1;
        for(int i=0;i<len;i++)
        {
            if(x1[v[i]]==2*x2[v[i]]||x2[v[i]]==x1[v[i]]*2||x1[v[i]]==x2[v[i]]&&x1[v[i]]%2==1||__gcd(x1[v[i]],x2[v[i]])!=1&&x1[v[i]]!=x2[v[i]])
            {
                continue;
            }else{
                flag=0;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
