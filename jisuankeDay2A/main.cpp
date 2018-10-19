#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[4],k,d,ans=0;
    int win[1000]={0};
    scanf("%d%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&k,&d);
    int sum=0;
    for(int i=0;i<4;i++)
    {
        sum+=num[i];
    }
    int t=0;
    for(int i=0;i<k;i++)
    {
        t+=num[i];
    }
    win[t-d+1]=win[t-d]=1;
//    if(k==1)
//        win[d]=win[d+1]=1;
//    else if(k==2)
//        win[num[0]+d]=win[num[0]+d+1]=1;
//    else if(k==3)
//        win[num[0]+num[1]+d]=win[num[0]+num[1]+d+1]=1;
//    else if(k==4)
//        win[num[0]+num[1]+num[2]+d]=win[num[0]+num[1]+num[2]+d+1]=1;
    win[0]=win[sum];
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int p=(i+j)%4;
            int res=0;
            if(p==0) p=4;
            for(int z=0;z<p;z++)
            {
                res+=num[z];
            }
            res=res-min(i,j);
            if(win[(res+sum)%sum]&&win[(res-1+sum)%sum]||win[(res-8+sum)%sum]&&win[(res-9+sum)%sum]||win[(res-16+sum)%sum]&&win[(res-17+sum)%sum])
                ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
