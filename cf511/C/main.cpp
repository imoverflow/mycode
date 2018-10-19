#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[300005];
map<int,int>mp;
int Mark[20000007];
int prime[20000007];
int mprime[20000007];
int Prime(){
	int index = 0;
	memset(Mark,0,sizeof(Mark));
    for(int i = 2; i < 15000007; i++)
    {
		if(Mark[i] == 0){
			mprime[i]=i;
			prime[index++] = i;
		}
		for(int j = 0; j < index && prime[j] * i < 15000007; j++)
        {
            mprime[i*prime[j]]=prime[j];
			Mark[i * prime[j]] = 1;
			if(i % prime[j] == 0){
                break;
			}
        }
    }
	return index;
}
int main()
{
    Prime();
    int n;
    cin>>n;
    int g,ma=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        ma=max(ma,s[i]);
        if(i){
            g=__gcd(g,s[i]);
        }
        else
            g=s[i];
    }
    if(g==ma)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        s[i]/=g;
    }
//    for(int i=2;i<10;i++)
//    {
//        cout<<mprime[i]<<" "<<endl;
//    }
    for(int i=0;i<n;i++)
    {
        set<int>ss;
        int t=s[i];
//        if(s[i]==1)
//        {
//            mp[1]++;
//            continue;
//        }
        while(s[i]>1)
        {
            ss.insert(mprime[s[i]]);
            s[i]/=mprime[s[i]];
        }
        for(auto j:ss)
        {
            mp[j]++;
        }
    }
    int ans=0;
    for(auto i:mp)
    {
        ans=max(ans,i.second);
    }
    cout<<n-ans<<endl;
    return 0;
}
