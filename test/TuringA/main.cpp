#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
double ans[16]={0};
double ans1;
bool dfs(int sum,int* used)
{
    int t[50];
    for(int i=0;i<50;i++)
    {
        t[i]=used[i];
    }
    if(sum%3==0&&sum!=0) return false;
    if(sum==((3*n+2)*(3*n+1))/2) return true;
    for(int i=1;i<=3*n+1;i++)
    {
        if(t[i]==0)
        {
            t[i]=1;
            if(dfs(sum+i,t))
                ans1+=1;
//            else
//                t[i]=0;
        }
    }
}
int main()
{
//    scanf("%d",&n);
//    double sum=1;
//    for(int i=1;i<=3*n+1;i++)
//    {
//        sum*=n;
//    }
    for(int j=1;j<=15;j++)
    {
        ans1=0;
        n=j;
        double sum=1;
        for(int k=1;k<=3*j+1;k++)
        {
            sum*=k;
        }
        int s[50]={0};
        dfs(0,s);
        printf("%f\n",ans1);
        printf("%.11f\n",ans[j]=ans1/sum);
    }

    return 0;
}
