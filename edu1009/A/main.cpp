#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    queue<int>q1;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        q1.push(a);
    }
    queue<int>q2;
    for(int i=0;i<m;i++){
        int a;
        scanf("%d",&a);
        q2.push(a);
    }
    int cnt=0;
    while(!q1.empty()&&!q2.empty()){
        int a=q1.front();
        q1.pop();
        int b=q2.front();
        if(a<=b){
            cnt++;
            q2.pop();
        }
    }
    cout<<cnt<<endl;
    return 0;
}
