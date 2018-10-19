#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int pos,spe,dir;
}s[100005];
int n,k;
double check(int m)
{
    double resl=1e9,resr=1e9;
    for(int i=0;i<n;i++)
    {
//        if(s[i].pos==m)
//        {
//            if(s[i].pos==1)
//                res=min(res,(double)s[i].pos/s[i].spe);
//            else
//                res=min(res,((double)1e6-s[i].pos)/s[i].spe);
//            continue;
//        }
        if(s[i].dir==1)
        {
            double t1=((double)m-s[i].pos)/(k-s[i].spe);
            double t2=((double)s[i].pos-s[i].spe*t1)/(s[i].spe+k)+t1;
            resl=min(resl,t2);
        }else{
            double t1=((double)s[i].pos-m)/(k-s[i].spe);
            double t2=(1e6-s[i].pos-(double)s[i].spe*t1)/(k+s[i].spe)+t1;
            resr=min(resr,t2);
        }
    }
    return max(resl,resr);
}
int main()
{
    double ans=1e9;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&s[i].pos,&s[i].spe,&s[i].dir);
        if(s[i].dir==1)
        {
            ans=min((double)s[i].pos/s[i].spe,ans);
        }else{
            ans=min((1e6-s[i].pos)/s[i].spe,ans);
        }
    }

    int l=0,r=1e6;
    int as=0;
    int lmid,rmid;
    while(l+2<r)
    {
        int lmid=l+(l+r)/3,rmid=r-(l+r)/3;
        if(check(lmid)<check(rmid))
        {
            r=rmid;
            as=rmid;
        }else{
            l=lmid;
            as=lmid;
        }
    }
    for(int i=l;i<=r;i++)
    {
        ans=min(check(i),ans);
    }
    printf("%f",ans);
    return 0;
}
