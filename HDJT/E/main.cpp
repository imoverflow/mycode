#include <bits/stdc++.h>
using namespace std;

long long n;
struct Matrix
{
    long long m[32][32];
};
Matrix a,per;
void init()
{
    long long i,j;
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
        {
            cin>>a.m[i][j];
            a.m[i][j]%=10;
            per.m[i][j]=(i==j);
        }
}

Matrix mul(Matrix A,Matrix B)
{
    Matrix ans;long long i,j,k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            ans.m[i][j]=0;
            for(k=0; k<n; k++)
                ans.m[i][j]+=(A.m[i][k]*B.m[k][j]);
            ans.m[i][j]%=10;
        }
    return ans;
}
Matrix power(long long k)
{
    Matrix p,ans=per;
    p=a;
    while(k)
    {
        if(k&1)
        {
            ans=mul(ans,p);
            --k;
        }
        else
        {
            k/=2;
            p=mul(p,p);
        }
    }
    return ans;
}

Matrix add(Matrix a,Matrix b)
{
    Matrix c;long long i,j;
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            c.m[i][j]=(a.m[i][j]+b.m[i][j])%10;
    return c;
}
Matrix sum(long long k)
{
    if(k==1) return a;
    Matrix temp,b;
    temp=sum(k/2);
    if(k&1)
    {
        b=power(k/2+1);
        temp=add(temp,mul(temp,b));
        temp=add(temp,b);
    }
    else
    {
        b=power(k/2);
        temp=add(temp,mul(temp,b));
    }
    return temp;
}

int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        init();
        Matrix ans=sum(k);
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n-1; ++j)
                printf("%d ",ans.m[i][j]);
            printf("%d\n",ans.m[i][n-1]);
        }
    }
    return 0;
}
