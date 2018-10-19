#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

char b[100005];
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%s",b);
    int x=0;
    int l=-INF,r=INF;
    for(int i=4;i<n;i++)
    {
        x<<=1;
        x+=b[i]-'0';
        x%=32;
        if(x==0)
        {
            int ma=-INF;
            for(int j=i;j>=i-4;j--)
            {
                ma=max(ma,a[j]);
            }
            l=min(l,ma);
        }else if(x==1){
            int ma=-INF;
            for(int j=i;j>=i-4;j--)
            {
                ma=max(ma,a[j]+1);
            }
            l=max(l,ma);
        }else if(x==31){
            int mi=INF;
            for(int j=i;j>=i-4;j--)
            {
                mi=min(mi,a[j]);
            }
            r=max(r,mi);
        }else if(x==30){
            int mi=INF;
            for(int j=i;j>=i-4;j--)
            {
                mi=min(mi,a[j]-1);
            }
            r=min(r,mi);
        }

    }
    printf("%d %d",l,r);
    return 0;
}
