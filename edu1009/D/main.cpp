#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long phi[100005];
long long sum[100005];

vector<pair<int,int> > v;
void init(){
    int cnt=0;
    for(int i=2;i<=100000;i++){
        for(int j=2;j<i;j++){
            if(__gcd(j,i)==1){
                v.push_back(make_pair(i,j));
                cnt++;
            }
            if(cnt>100000)
                break;
        }
        if(cnt>100000){
            break;
        }
    }

    for(int i=2;i<=100000;i++)
        phi[i]=0;
    phi[1]=1;
    for(int i=2;i<=100000;i++){
        if(!phi[i]){
            for(int j=i;j<=100000;j+=i){
                if(!phi[j]) phi[j]=j;
                    phi[j]=phi[j]/i*(i-1);
            }
        }
    }
    sum[0]=0;
    for(int i=1;i<=100000;i++){
        sum[i]=sum[i-1]+phi[i];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    init();
//    for(int i=1;i<=10;i++)
//    {
//        cout<<sum[i]<<endl;
//    }
    if(sum[n]>m&&m>=n-1){
        printf("Possible\n");
        for(int i=2;i<=n;i++){
            printf("%d %d\n",1,i);
        }
        for(int i=0;i<m-n+1;i++){
            printf("%d %d\n",v[i].first,v[i].second);
        }
    }else{
        printf("Impossible\n");
    }
    return 0;
}
