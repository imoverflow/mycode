#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    sort(s,s+n);
    s[n]=-1;
    int cnt=0;
    for(int i=0,j=0;i<n&&j<n;i++){
        while(s[i]>=s[j]){
            j++;
        }
        if(j<n)
            cnt++;
        j++;
    }
    cout<<cnt<<endl;
    return 0;
}
