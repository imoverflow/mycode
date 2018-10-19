#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long N = 200000;
long long prime[N] = {0},num_prime = 0;
long long isNotPrime[N] = {1, 1};
void init()
{
    for(long long i=2;i<N;i++)
    {
        if(!isNotPrime[i])
            prime[num_prime++]=i;
        for(long long j=0;j<num_prime&&i*prime[j]<N;j++)
        {
            isNotPrime[i*prime[j]] = 1;
            if(!(i%prime[j]))
                break;
        }
    }
}
int main()
{
    init();
    int cas=1;
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        printf("Case %d: %lld\n",cas++,prime[n-1]);
    }
    return 0;
}
