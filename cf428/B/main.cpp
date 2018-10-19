#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&s[i]);
    }
    long long ans=0;
    int cnt1=n,cnt2=n*2,cnt3=0;        // m lr
    for(int i=0;i<k;i++)
    {
        if(s[i]%4==0)
        {
            cnt1-=s[i]/4;
            if(cnt1<0)
            {
                cnt2-=abs(cnt1)*2;
                cnt1=0;
            }
        }else if(s[i]%4==2)
        {
            cnt2-=s[i]/2;
            while(cnt2<0&&cnt1>0)
            {
                cnt1--;
                cnt2++;
                cnt3++;
            }
        }else if(s[i]%4==1)
        {
            if(cnt3>0) cnt3--;
            else cnt1--;
            cnt1-=s[i]/4;
            if(cnt1<0)
            {
                cnt2-=abs(cnt1)*2;
                cnt1=0;
            }
            cnt2++;
        }else if(s[i]%4==3)
        {
            if(cnt3>=3)
            {
                cnt1-=(s[i]/4);
                cnt3-=3;
            }
            else cnt1-=(s[i]+1)/4;
            if(cnt1<0)
            {
                cnt2-=abs(cnt1)*2;
                cnt1=0;
            }
        }
    }
    if(cnt2>=0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
