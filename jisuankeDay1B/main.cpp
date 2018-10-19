#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int w[1000006]={0};
char s[1000005]={0};
char t[1000005];
int main()
{
    int n,a,b,L,R,ans=0;
    scanf("%d%d%d%d%d",&n,&a,&b,&L,&R);
    scanf("%s",t);
    for(int i=0;i<=n;i++)
    {
        if(i==0) w[i]=b;
        else w[i]=(w[i-1]+a)%n;
    }
    int flag=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(L<=w[i]&&R>=w[i]&&w[i]%2==0)
            s[i]='A';
        else if(L<=w[i]&&R>=w[i]&&w[i]%2==1)
            s[i]='T';
        else if((L>w[i]||R<w[i])&&w[i]%2==0)
            s[i]='G';
        else if((L>w[i]||R<w[i])&&w[i]%2==1)
            s[i]='C';
        if(s[i]==t[k])
        {
            k++;
            if(k==strlen(t))
            {
                k=0;
                ans++;
            }
        }else{
            k=0;
            if(i>0&&s[i-1]==t[0])
                k++;
        }
    }
    s[n]='\0';
    printf("%s",s);
    printf("%d",ans);
    return 0;
}
