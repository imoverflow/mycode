#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
int m[N],phi[N],p[N],nump;
int make()
{
    phi[1]=1;
    for (int i=2;i<=N-2;i++)
    {
        if (!m[i])
        {
            p[++nump]=i;
            phi[i]=i-1;
        }
        for (int j=1;j<=nump&&p[j]*i<N-2;j++)
        {
            m[p[j]*i]=1;
            if (i%p[j]==0) {
                phi[p[j]*i]=phi[i]*p[j];
                break;
            }
            else phi[p[j]*i]=phi[i]*(p[j]-1);
        }
    }
}
void G(int a,int b,long long &x1,long long &x2)
{
    x1=phi[a*b];
    x2=phi[a]*phi[b];
    long long d=__gcd(x1,x2);
    x1/=d;
    x2/=d;
}
vector<pair<int,int>>v[100];
map<pair<int,int> ,int>ma;
int main()
{
    freopen("out.txt","w",stdout);
    make();
    printf("%d\n",nump);
    int cnt=1;
    for(int i=1;i<=100;i++)
    {
        for(int j=i;j<=100;j++)
        {
            long long a,b;
            G(i,j,a,b);
            if(ma[make_pair(a,b)]==0)
            {
                ma[make_pair(a,b)]=cnt;
                v[cnt].push_back(make_pair(i,j));
                cnt++;
            }else{
                v[ma[make_pair(a,b)]].push_back(make_pair(i,j));
            }
        }
    }
    for(auto i:ma)
    {
        printf("%d/%d\n",i.first.first,i.first.second);
        for(int j=0;j<v[i.second].size();j++)
        {
            printf("(%d,%d)\n",v[i.second][j]);
        }
        printf("\n");
    }
    return 0;
}
