#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[100000];
bool cmp(const int &a ,const int &b)
{
    return a<b;
}
int main()
{
    int k;
    cin>>k;
    getchar();
    char t;
    int cnt=0;
    int sum=0;
    int mi=10;
    while(scanf("%c",&t))
    {
        if(t<'0'||t>'9')
            break;
        s[cnt++]=t;
        sum+=t-'0';
        mi=min(mi,t-'0');
    }
    if(sum>=k)
    {
        printf("0\n");
    }else{
        int x=0;
        for(int i=0;i<mi;i++)
        {
            x+=mi*2;
        }
        sort(s,s+cnt,cmp);
        int ans=0;
        for(int i=0;i<cnt;i++)
        {
            if(k-sum>0)
            {
                k-='9'-s[i];
                ans++;
            }else{
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
