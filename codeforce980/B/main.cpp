#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char ans[4][1000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(k%2==0)
    {
        for(int i=1;i<=k/2;i++)
        {
            ans[1][i]='#';
            ans[2][i]='#';
        }
        cout<<"YES"<<endl;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]=='#')
                    printf("%c",ans[i][j]);
                else
                    printf(".");
            }
            printf("\n");
        }
    }else{
        for(int i=n/2,j=0;j<=n/2;j++)
        {
            if(!k) break;
            if(j==0)
            {
                ans[1][i]='#';
                k--;
            }else{
                ans[1][i+j]='#';
                ans[1][i-j]='#';
                k-=2;
                if(k)
                {
                    ans[2][i+j]='#';
                    ans[2][i-j]='#';
                    k-=2;
                }
            }
        }
        cout<<"YES"<<endl;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]=='#')
                    printf("%c",ans[i][j]);
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    return 0;
}
