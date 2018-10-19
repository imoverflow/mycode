#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<int,int>ma;
int main()
{
    int n;
    cin>>n;
    int fi[500];
    fi[1]=1;
    fi[2]=1;
    ma[1]++;
    ma[2]++;
    for(int i=3;i<500;i++)
    {
        fi[i]=fi[i-1]+fi[i-2];
        ma[fi[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(ma[i]!=0)
        {
            printf("O");
        }else{
            printf("o");
        }
    }
    return 0;
}
