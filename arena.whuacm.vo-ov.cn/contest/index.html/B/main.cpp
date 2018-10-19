#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t[]={1,2,3,4,5,6,7,8};
    for(int x=2;x<=7;x++)
    {
        int cnt[100]={0};
        do{
            int tt[100];
            for(int i=0;i<x;i++)
            {
                tt[i]=t[i];
            }
            int res=0;
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<x-1;j++)
                {
                    if(tt[j]>tt[j+1])
                    {
                        swap(tt[j],tt[j+1]);
                        res++;
                    }
                }
            }
            cnt[res]++;
        }while(next_permutation(t,t+x));
        long long ans=0;
        for(int i=0;i<25;i++)
        {
            cout<< cnt[i]<<" ";
            ans+=cnt[i]*i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
