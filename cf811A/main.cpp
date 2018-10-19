#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    long long cnt=1;
    int flag;
    while(a>=0&&b>=0)
    {
        if(cnt%2==1){
            a-=cnt;
        }else{
            b-=cnt;
        }
        cnt++;
    }
    if(b<0)
    {
        printf("Valera\n");
    }else if(a<0){
        printf("Vladik\n");
    }
    return 0;
}
