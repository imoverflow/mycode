#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<int>v(1000006);
int main()
{
//    ios::sync_with_stdio(false);
    int n,t;
    scanf("%d%d",&n,&t);
//    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        v[i]=i+1;
    }
    while(t--)
    {
        int p,x;
        scanf("%d%d",&p,&x);
        if(p==1)
            continue;
        v.insert(v.begin(),v.begin()+p-1,v.begin()+p+x-1);
        for(int i=0;i<10;i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
        v.erase(v.begin()+x+p-1,v.begin()+x+x+p-1);
        for(int i=0;i<10;i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}

/*
5 1
2 3

5 3
2 3
2 4
1 4
*/
