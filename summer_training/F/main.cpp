#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long powa(int a,int b)
{
    long long res=1;
    for(int i=0;i<b;i++)
    {
        res*=a;
    }
    return res;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n)){
        if(n<=25)
        {
            printf("%c",n+'A');
            continue;
        }
        long long s[15];
        s[0]=0;
        for(int i=1;i<11;i++)
        {
            s[i]=i*powa(26,i)-1;
        }
        int pp=1;
        for(int i=1;i<10;i++)
        {
            if(n>s[i]&&n<=s[i+1])
            {
                pp=i+1;
                n-=s[i];
                break;
            }
        }
        long long cc,rr;
        rr=n/(26*pp);
//        if(n%(26*pp)!=0)
//            rr++;
        cc=(n-rr*26*pp)/pp;
        int rowname[20]={0};
        int cnt=1;
        while(rr>0)
        {
            rowname[cnt++]=rr%26;
            rr/=26;
        }
        for(int i=0;i<10;i++)
        {
            rowname[i]+='A';
        }
        int index=n%pp;
        rowname[0]+=(cc-1)%26;
        printf("%c\n",rowname[index]);
    }
    return 0;
}
