#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1000];
long long b[1000];
long long r[105];
long long c[105];
long long ans[105][105];
int main()
{
    int n,m;
    cin>>n>>m;
    long long maxx=0;
    long long res=0;
    memset(ans,0,sizeof ans);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        maxx=max(maxx,a[i]);
        res^=a[i];
    }
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&b[i]);
        maxx=max(maxx,b[i]);
        res^=b[i];
    }
    if(res!=0)
    {
        printf("NO\n");
        return 0;
    }
    bool flag=true;
    for(long long p=0;(1<<p)<=2*maxx;p++)
    {
        memset(c,0,sizeof c);
        memset(r,0,sizeof r);
        for(int i=0;i<n-1;i++)
        {
            if((a[i]&(1LL<<p))!=0)
            {
                if(m%2==1){
                    for(int j=0;j<m;j++)
                    {
                        ans[i][j]|=(1LL<<p);
                        c[j]++;
                        r[i]++;
                    }
                }else{
                    for(int j=0;j<m-1;j++)
                    {
                        ans[i][j]|=(1LL<<p);
                        c[j]++;
                        r[i]++;
                    }
                }
            }else{
                if(m%2==1){
                    for(int j=0;j<m-1;j++)
                    {
                        ans[i][j]|=(1LL<<p);
                        c[j]++;
                        r[i]++;
                    }
                }else{
                    for(int j=0;j<m;j++)
                    {
                        ans[i][j]|=(1LL<<p);
                        c[j]++;
                        r[i]++;
                    }
                }
            }
        }
//        long long res=0;
//        for(int i=0;i<n;i++)
//        {
//            res+=(r[i]%2==1);
//        }
//        for(int i=0;i<m;i++)
//        {
//            res+=(c[i]%2==1);
//        }
//        if(n*m%2==1)
//        {
//            if(res%2==0)
//            {
//                flag=false;
//                break;
//            }
//        }else{
//            if(res%2==1)
//            {
//                flag=false;
//                break;
//            }
//        }
        for(int i=0;i<m;i++)
        {
            if((b[i]&(1<<p))!=0)
            {
                if(c[i]%2==1)
                {
                    ;
                }else{
                    ans[n-1][i]|=(1LL<<p);
                }
            }else{
                if(c[i]%2==1)
                {
                    ans[n-1][i]|=(1LL<<p);
                }else{
                    ;
                }
            }
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printf("%lld ",ans[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("NO\n");
    }
    return 0;
}
